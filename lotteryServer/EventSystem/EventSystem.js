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

EventSystem.prototype.removeDelaySchedule = function(handler){
    this.clearTimeout(handler);
}

EventSystem.prototype.processNextTick = function(handler){
    process.nextTick(handler);
};

EventSystem.prototype.tickSchedule = function(tickTime, handler){
    this.setInterval(handler, tickTime);
};

EventSystem.prototype.removeTickSchedule = function(handler){
    this.clearInterval(handler);
}

EventSystem.prototype.registerHandler = function(eventName, handler){
    /*if (null == this.event_handler_pool[event_name]){
        this.event_handler_pool[event_name] = new Array();
    }
    var handlers = this.event_handler_pool[event_name];
    handlers.push(handler);
    */
    this.on(eventName, handler);
};

EventSystem.prototype.unregisterHandler = function(eventName, handler){
    /*if (null != this.event_handler_pool[event_name]) {
        var handlers = this.event_handler_pool[event_name];
        for (var i = 0; i < handlers.length; i++){
            if (handlers[i] == handler){
                handlers[i] = null;
            }
        }
    }*/
    this.removeListener(eventName, handler);
};

EventSystem.prototype.unregisterAllHandler = function(eventName){
    this.removeAllListeners(eventName);
}

EventSystem.prototype.emitEvent = function(eventName, parm1, parm2, parm3, parm){
    this.emit(eventName, parm1, parm2, parm3, parm);
};

util.inherits(EventSystem, EventEmitter);

module.exports = EventSystem;