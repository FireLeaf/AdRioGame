var PlayerManager = require("./PlayerManager.js")

function GameLogic(){
    this.playerManager = new PlayerManager();
}

GameLogic.prototype.GetPlayerManager = function(){return this.playerManager;};

GameLogic.prototype.HandlerPacket = function(res, req, packet){
    var net_id = packet["id"];
    if (net_id == NC_TS_LOGINREQUEST){

    }
    else {
        var uid = packet["uid"];
        if (!this.IsUserLogined(uid)){
            return;//��ǰ�û��Ѿ���¼
        }
    }
};

module.exports = new GameLogic();

