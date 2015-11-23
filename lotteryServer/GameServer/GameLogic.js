var player = require("./Player/Player.js")

function GameLogic(){
    this.players = {};//new Array();
    this.cache_players = {};
}

GameLogic.prototype.HandlerPacket = function(res, req, packet){
    var net_id = packet["id"];
    if (net_id == NC_TS_LOGINREQUEST){

    }
    else {
        var uid = packet["uid"];
        if (!this.IsUserLogined(uid)){
            return;//当前用户已经登录
        }
    }
    //switch() {
    //    case NC_TS_LOGINREQUEST:
    //
    //        break;
    //    default :
    //        break;
    //}
}

GameLogic.prototype.FindPlayer = function(uid){
    return this.players[uid];
}

GameLogic.prototype.IsUserLogined = function(uid){
    var cur_player = this.FindPlayer(uid);
    if ( cur_player && cur_player.IsEnable() ){
        return true;
    }
}

GameLogic.prototype.KickoutPlayer = function(uid){
    //for (var i = 0; i <  this.players.length(); i++){
    //    var cur_player = this.players[i];
    //    if (cur_player && cur_player.IsEnable() && cur_player.GetUID() == uid){
    //        cur_player.Leave();
    //    }
    //}

    var cur_player = this.FindPlayer(uid);
    if (cur_player && cur_player.IsEnable() && cur_player.GetUID() == uid){
        cur_player.Leave();
        this.cache_players[uid] = cur_player;
    }
}