/**
 * Created by Administrator on 2015/11/23.
 */

function Player(){
    this.uid = 0;//�û�ID
    this.name = "";//�û���
    this.money = 0;//�û���Ǯ
    this.cash = 0;//�û�Ԫ��
    this.last_op_stamp = 0;//�ϴβ���ʱ��
    this.enable = false;//��ǰ�Ƿ񼤻�
    this.cache_msg = [];
}

Player.prototype.GetUID = function(){return this.uid;};
Player.prototype.SetUID = function(uid){this.uid = uid;};

Player.prototype.GetLastStamp = function(){return this.last_op_stamp;};
//Player.prototype.SetLastStamp = function(stamp){this.last_op_stamp = uid;};

Player.prototype.IsEnable = function(){return this.enable;};
Player.prototype.Enable = function(enable){this.enable = enable;};


Player.prototype.HandlerPacket = function(res, req, packet) {

};

//��ҽ���������Ҫ��ʼ������Դ
Player.prototype.Enter = function(){
    this.Enable(true);
    this.Refrash();
};

//����뿪������Ҫ�ͷ��Լ����ݳ־û��Ĳ���
Player.prototype.Leave = function(){
    this.Enable(false);
    this.last_op_stamp = 0;
};

//������Ҳ�����ʱ���
Player.prototype.Refrash = function(){
    //��ȡʱ���
    this.last_op_stamp = Data.getTime();//Date.now();
};

modules.exports = Player;