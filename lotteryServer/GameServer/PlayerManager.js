/**
 * Created by YangCao on 2015/12/2.
 */
var player = require("./Player/Player.js")

var Max_Online_Player = 1000;
var Max_Zombie_Time = 300;
function PlayerManager(){
    this.players = {};//new Array();//在线玩家表
    this.online_count = 0;//在线玩家数量
    this.cache_players = [];//玩家缓存，用栈来操作，一般是被踢掉或者离线的
    this.cache_count = 0;//缓存大小
}
//查找某个在线的玩家
PlayerManager.prototype.FindPlayer = function(uid){
    return this.players[uid];
};
//某个用户是否登录
PlayerManager.prototype.IsUserLogined = function(uid){
    var cur_player = this.FindPlayer(uid);
    if ( cur_player && cur_player.IsEnable() ){
        return true;
    }
    return false;
};
//接收新登录的玩家
PlayerManager.prototype.DeliverPlayer = function(uid){
    //当前玩家已经登录
    if (this.IsUserLogined(uid)){
        return ErrorCode.EC_LOGIN_REPEAT;
    }

    if (this.online_count >= Max_Online_Player){
        //如果没有踢掉一个或者踢了之后在线 人数还是很多，那么表示服务器爆满
        if (!this.KickoutZombiePlayer() || this.online_count >= Max_Online_Player){
            return ErrorCode.EC_SERVER_FULL;
        }
    }

    var newPlayer = this.FindEmptyCachePlayer();
    if (!newPlayer){
        newPlayer = new player;
    }
    if (!newPlayer){
        return ErrorCode.EC_UNKONW;
    }

    this.players[uid] = newPlayer;
    this.online_count++;
    newPlayer.Enter();

    return ErrorCode.EC_SUCCESS;
};
//从cache表中抓取一个
PlayerManager.prototype.FindEmptyCachePlayer = function(){
    if (this.cache_count <= 0){
        return null;
    }
    var cachePlayer = this.cache_players.pop();
    if (cachePlayer){
        this.cache_count--;
        return cachePlayer;
    }
};

//踢掉玩家
PlayerManager.prototype.KickoutPlayer = function(uid){
    var cur_player = this.FindPlayer(uid);
    if (cur_player && cur_player.IsEnable() && cur_player.GetUID() == uid){
        this.players[uid] = null;
        cur_player.Leave();
        this.cache_players.push(cur_player);
        this.cache_count++;
    }
};

//踢掉长久不操作的僵尸玩家
PlayerManager.prototype.KickoutZombiePlayer = function(){
    for (var uid in this.players){
        if (this.players[uid] && this.players[uid] instanceof player){
            var curTime = Data.getTime();
            var lastTime = this.players[uid].GetLastStamp();
            //判断当前和上一次操作的时间戳
            if (curTime - lastTime > Max_Zombie_Time){
                this.KickoutPlayer(uid);
                return true;
            }
        }
    }
    return false;
};

module.exports = PlayerManager;