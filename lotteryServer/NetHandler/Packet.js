/**
 * Created by YangCao on 2015/12/1.
 */
var util = require("util");
function Packet(){
    this.packet_data = {}
}

Packet.prototype.checkPacket = function(){
};

Packet.prototype.fillPacket = function(packetdata){
    this.packet_data = packetdata;
};

Packet.prototype.handlePacket = function(){

};

Packet.prototype.responeClient = function(packetMsg){
    res.writeHead(200, {
        "Content-Type": "application/json;charset=utf-8"
    });
    //var data = { id: 0, data: {
    //    dir: 'kunhony',
    //    param: 'archive' }
    //};
    res.end(JSON.stringify(packetMsg));
};

Packet.newPacket = function(packetClass, packetData){
    var new_packet = new packetClass();
    new_packet.fillPacket(packetData);
    if (!new_packet.checkPacketImp()){
        return null;
    }
    return new_packet;
};

Packet.inherits = function(packetClass){
    util.inherits(packetClass, Packet);
};

module.exports = Packet;