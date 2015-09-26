/**
 * Created by Administrator on 2015/9/21.
 */
var util = require("util");
var Room = require("./Room.js");
function LotteryRoom(){

}

util.inherits(LotteryRoom, Room);
module.exports = LotteryRoom;