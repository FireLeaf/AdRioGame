/**
 * Created by YangCao on 2015/12/2.
 */
var player = require("./Player/Player.js")

var Max_Online_Player = 1000;
var Max_Zombie_Time = 300;
function PlayerManager(){
    this.players = {};//new Array();//������ұ�
    this.online_count = 0;//�����������
    this.cache_players = [];//��һ��棬��ջ��������һ���Ǳ��ߵ��������ߵ�
    this.cache_count = 0;//�����С
}
//����ĳ�����ߵ����
PlayerManager.prototype.FindPlayer = function(uid){
    return this.players[uid];
};
//ĳ���û��Ƿ��¼
PlayerManager.prototype.IsUserLogined = function(uid){
    var cur_player = this.FindPlayer(uid);
    if ( cur_player && cur_player.IsEnable() ){
        return true;
    }
    return false;
};
//�����µ�¼�����
PlayerManager.prototype.DeliverPlayer = function(uid){
    //��ǰ����Ѿ���¼
    if (this.IsUserLogined(uid)){
        return ErrorCode.EC_LOGIN_REPEAT;
    }

    if (this.online_count >= Max_Online_Player){
        //���û���ߵ�һ����������֮������ �������Ǻܶ࣬��ô��ʾ����������
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
//��cache����ץȡһ��
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

//�ߵ����
PlayerManager.prototype.KickoutPlayer = function(uid){
    var cur_player = this.FindPlayer(uid);
    if (cur_player && cur_player.IsEnable() && cur_player.GetUID() == uid){
        this.players[uid] = null;
        cur_player.Leave();
        this.cache_players.push(cur_player);
        this.cache_count++;
    }
};

//�ߵ����ò������Ľ�ʬ���
PlayerManager.prototype.KickoutZombiePlayer = function(){
    for (var uid in this.players){
        if (this.players[uid] && this.players[uid] instanceof player){
            var curTime = Data.getTime();
            var lastTime = this.players[uid].GetLastStamp();
            //�жϵ�ǰ����һ�β�����ʱ���
            if (curTime - lastTime > Max_Zombie_Time){
                this.KickoutPlayer(uid);
                return true;
            }
        }
    }
    return false;
};

module.exports = PlayerManager;