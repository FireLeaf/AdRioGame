/**
 * Created by YangCao on 2015/12/2.
 */

require("./NetCode.js")

function PacketFactory(){
    this.create_factory = {}
}

PacketFactory.prototype.InitRegister = function(){
    this.RegisterPacket(OG_NetCode.NC_C_LOGINREQUEST, require("./Packet/LoginReqPacket"));
    return this;
};

PacketFactory.prototype.RegisterPacket = function(id, factory){
    this.create_factory[id] = factory;
};

PacketFactory.prototype.CreatePacket = function(packetData){
    var packet_id = packetData.id;
    if (packet_id == null){
        return null;
    }
    if(this.create_factory[packet_id]){
        return this.create_factory[packet_id](packetData);
    }
};

module.exports = (new PacketFactory()).InitRegister();