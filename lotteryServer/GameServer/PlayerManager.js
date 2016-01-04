/**
 * Created by YangCao on 2015/12/2.
 */
var Player = require("./Player/Player.js")

var Max_Online_Player = 1000;
var Max_Zombie_Time = 300;

PM_ErrorCode = {
    PM_SUCCESS : 0,//成功
    PM_USER_OFFLINE : 1,//玩家处于离线状态
    PM_USER_IN_LOCK : 2,//玩家处于处理锁区域
};

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

//某个用户是否可以正常处理消息
PlayerManager.prototype.CheckUserAvailable = function(uid){
    if ( !this.IsUserLogined(uid) ){
        return PM_ErrorCode.PM_USER_OFFLINE;
    }

    var cur_payer = this.FindPlayer(uid);
    if (cur_payer && cur_payer.InLock()){
        return PM_ErrorCode.PM_USER_IN_LOCK;
    }

    return PM_ErrorCode.PM_SUCCESS;
}

//接收玩家回调
PlayerManager.prototype.OnDeliverPlayerHandler = function(error, player){
    var uid = player.GetUID();
    if (error > 0){
        //如果有错误，而且在玩家列表对应的位置是当前player对象，那么踢掉当前的玩家
        if (this.players[uid] == player){
            this.players[uid] = null;
            this.online_count--;
            this.OnKickoutPlayerHandler(0, player);
        }
        else {
            //表示未知的错误
            alert(0);
        }
    } else {

    }
    //解锁当前玩家
    player.LeaveLock();
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

    //在cache中寻找一个玩家，，如果没有找见就新建一个
    var newPlayer = this.FindEmptyCachePlayer();
    if (!newPlayer){
        newPlayer = new Player;
        //if (newPlayer == null){
        //    return ErrorCode.EC_SERVER_EXCEPTION;
        //}
    }
    if (!newPlayer){
        return ErrorCode.EC_UNKONW;
    }
    newPlayer.EnterLock();

    this.players[uid] = newPlayer;
    this.online_count++;
    //玩家进入逻辑，进入完成后就
    newPlayer.Enter(this, function(error, player, playerManager){
        playerManager.OnDeliverPlayerHandler(error, player);
    });

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
    return null;
};

//真正踢掉玩家的回调
PlayerManager.prototype.OnKickoutPlayerHandler = function(error, player){
    if (error > 0){
        //如果有错误
    } else {
        //没有错误

    }
    //有没有错误都得踢掉
    this.cache_players.push(cur_player);
    this.cache_count++;
};

//踢掉玩家
PlayerManager.prototype.KickoutPlayer = function(uid){
    var cur_player = this.FindPlayer(uid);
    if (cur_player && cur_player.IsEnable() && cur_player.GetUID() == uid){
        this.players[uid] = null;
        //leave可能是一个异步的操作，需要向数据库写入玩家数据
        cur_player.Leave(this, function(error, player, playerManager){
            playerManager.OnKickoutPlayerHandler(error, player);
        });
        return true;
    }
    return false;
};

//踢掉长久不操作的僵尸玩家
PlayerManager.prototype.KickoutZombiePlayer = function(){
    for (var uid in this.players){
        if (this.players[uid] && this.players[uid] instanceof player){
            var curTime = Data.getTime();
            var lastTime = this.players[uid].GetLastStamp();
            //判断当前和上一次操作的时间戳
            if (curTime - lastTime > Max_Zombie_Time){
                return this.KickoutPlayer(uid);
            }
        }
    }
    return false;
};

module.exports = PlayerManager;