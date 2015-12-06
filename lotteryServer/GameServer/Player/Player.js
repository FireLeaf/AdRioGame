/**
 * Created by Administrator on 2015/11/23.
 */

function Player(){
    this.uid = 0;//用户ID
    this.name = "";//用户名
    this.money = 0;//用户金钱
    this.cash = 0;//用户元宝
    this.last_op_stamp = 0;//上次操作时间
    this.enable = false;//当前是否激活
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

//玩家进入世界需要初始化的资源
Player.prototype.Enter = function(){
    this.Enable(true);
    this.Refrash();
};

//玩家离开世界需要释放以及数据持久化的操作
Player.prototype.Leave = function(){
    this.Enable(false);
    this.last_op_stamp = 0;
};

//更新玩家操作的时间戳
Player.prototype.Refrash = function(){
    //获取时间戳
    this.last_op_stamp = Data.getTime();//Date.now();
};

modules.exports = Player;