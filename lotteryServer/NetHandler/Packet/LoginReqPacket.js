/**
 * Created by YangCao on 2015/12/1.
 */
var Packet = require("../Packet.js");
var util = require("util");

function LoginReqPacket(){

}
Packet.inherits(LoginReqPacket);

LoginReqPacket.prototype.checkPacketImp = function(){
    return true;
};

LoginReqPacket.prototype.handlePacketImp = function(){
    return true;
};
//var pk = new  LoginReqPacket();
module.exports = function(packetData){
   return Packet.newPacket(LoginReqPacket,  packetData);
};