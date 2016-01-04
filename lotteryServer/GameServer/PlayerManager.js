/**
 * Created by YangCao on 2015/12/2.
 */
var Player = require("./Player/Player.js")

var Max_Online_Player = 1000;
var Max_Zombie_Time = 300;

PM_ErrorCode = {
    PM_SUCCESS : 0,//�ɹ�
    PM_USER_OFFLINE : 1,//��Ҵ�������״̬
    PM_USER_IN_LOCK : 2,//��Ҵ��ڴ���������
};

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

//ĳ���û��Ƿ��������������Ϣ
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

//������һص�
PlayerManager.prototype.OnDeliverPlayerHandler = function(error, player){
    var uid = player.GetUID();
    if (error > 0){
        //����д��󣬶���������б��Ӧ��λ���ǵ�ǰplayer������ô�ߵ���ǰ�����
        if (this.players[uid] == player){
            this.players[uid] = null;
            this.online_count--;
            this.OnKickoutPlayerHandler(0, player);
        }
        else {
            //��ʾδ֪�Ĵ���
            alert(0);
        }
    } else {

    }
    //������ǰ���
    player.LeaveLock();
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

    //��cache��Ѱ��һ����ң������û���Ҽ����½�һ��
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
    //��ҽ����߼���������ɺ��
    newPlayer.Enter(this, function(error, player, playerManager){
        playerManager.OnDeliverPlayerHandler(error, player);
    });

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
    return null;
};

//�����ߵ���ҵĻص�
PlayerManager.prototype.OnKickoutPlayerHandler = function(error, player){
    if (error > 0){
        //����д���
    } else {
        //û�д���

    }
    //��û�д��󶼵��ߵ�
    this.cache_players.push(cur_player);
    this.cache_count++;
};

//�ߵ����
PlayerManager.prototype.KickoutPlayer = function(uid){
    var cur_player = this.FindPlayer(uid);
    if (cur_player && cur_player.IsEnable() && cur_player.GetUID() == uid){
        this.players[uid] = null;
        //leave������һ���첽�Ĳ�������Ҫ�����ݿ�д���������
        cur_player.Leave(this, function(error, player, playerManager){
            playerManager.OnKickoutPlayerHandler(error, player);
        });
        return true;
    }
    return false;
};

//�ߵ����ò������Ľ�ʬ���
PlayerManager.prototype.KickoutZombiePlayer = function(){
    for (var uid in this.players){
        if (this.players[uid] && this.players[uid] instanceof player){
            var curTime = Data.getTime();
            var lastTime = this.players[uid].GetLastStamp();
            //�жϵ�ǰ����һ�β�����ʱ���
            if (curTime - lastTime > Max_Zombie_Time){
                return this.KickoutPlayer(uid);
            }
        }
    }
    return false;
};

module.exports = PlayerManager;