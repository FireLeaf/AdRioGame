/**
 * Created by Administrator on 2015/9/16.
 */
var EventEmitter = require("events").EventEmitter;
var util = require("util");

var EventSystem = function(){
    this.event_handler_pool = {};
};

EventSystem.prototype.delaySchedule = function(delayTime, handler){
    this.setTimeout(handler, delayTime);
};

EventSystem.prototype.processNextTick = function(handler){
    process.nextTick(handler);
};

EventSystem.prototype.tickSchedule = function(tickTime, handler){
    this.setInterval(handler, tickTime);
};

EventSystem.prototype.registerHandler = function(eventName, handler){
    if (null == this.event_handler_pool[event_name]){
        this.event_handler_pool[event_name] = new Array();
    }
    var handlers = this.event_handler_pool[event_name];
    handlers.push(handler);
};

EventSystem.prototype.unregisterHandler = function(eventName, handler){
    if (null != this.event_handler_pool[event_name]) {
        var handlers = this.event_handler_pool[event_name];
        for (var i = 0; i < handlers.length; i++){
            if (handlers[i] == handler){
                handlers[i] = null;
                return true;
            }
        }
    }
    return false;
};

EventSystem.prototype.emitEvent = function(){

};

util.inherits(EventSystem, EventEmitter);

module.exports = EventSystem;