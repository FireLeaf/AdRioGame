/**
 * Created by Administrator on 2015/11/23.
 */

var PlayerDB = require("../DB/PlayerDB.js")

function Player(){
    this.enter_lock = false;//��������
    this.uid = 0;//�û�ID
    this.name = "";//�û���
    this.money = 0;//�û���Ǯ
    this.cash = 0;//�û�Ԫ��
    this.last_op_stamp = 0;//�ϴβ���ʱ��
    this.enable = false;//��ǰ�Ƿ񼤻�
    this.cache_msg = [];
    this.playerDB = new PlayerDB();
}

Player.prototype.GetUID = function(){return this.uid;};
Player.prototype.SetUID = function(uid){this.uid = uid;};

Player.prototype.GetLastStamp = function(){return this.last_op_stamp;};
//Player.prototype.SetLastStamp = function(stamp){this.last_op_stamp = uid;};

Player.prototype.IsEnable = function(){return this.enable;};
Player.prototype.Enable = function(enable){this.enable = enable;};

//��������
Player.prototype.EnterLock = function(){this.enter_lock = true;};
Player.prototype.LeaveLock = function(){this.enter_lock = false;};
Player.prototype.InLock = function(){return this.enter_lock;};

Player.prototype.HandlerPacket = function(res, req, packet) {

};

//��ҽ���������Ҫ��ʼ������Դ, function(error, player, playerManager)
Player.prototype.Enter = function(playerManager, callback){
    this.Enable(true);
    this.Refrash();
};

//����뿪������Ҫ�ͷ��Լ����ݳ־û��Ĳ���, function(error, player, playerManager)
Player.prototype.Leave = function(playerManager, callback){
    this.Enable(false);
    this.last_op_stamp = 0;
};

//������Ҳ�����ʱ���
Player.prototype.Refrash = function(){
    //��ȡʱ���
    this.last_op_stamp = Data.getTime();//Date.now();
};

//���������д���ļ���
Player.prototype.FFlush = function(dir, cause){
    var path = dir + "/" + this.GetUID + "_" + cause;
    var fs = require("fs");
    var fd = fd.openSync(path, "w");
    if (fd){
        var jsonData = JSON.stringify(this.playerDB.GetFlushData());
        var c = fs.writeSync(fd, jsonData, 0, jsonData.length, 0);
        fs.close(fd);
    } else{

    }
};

modules.exports = Player;