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
    this.cache_msg = new Array();
}

Player.prototype.GetUID = function(){return this.uid;}
Player.prototype.SetUID = function(uid){this.uid = uid;}

Player.prototype.IsEnable = function(){return this.enable;}
Player.prototype.Enable = function(enable){this.enable = enable;}


Player.prototype.HandlerPacket = function(res, req, packet) {

}

//��ҽ���������Ҫ��ʼ������Դ
Player.prototype.Enter = function(){
    this.Enable(true);
}

//����뿪������Ҫ�ͷ��Լ����ݳ־û��Ĳ���
Player.prototype.Leave = function(){
    this.Enable(false);
}

modules.exports = Player;