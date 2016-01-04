/**
 * Created by YangCao on 2015/12/10.
 */

//日志管理

var log4js = require("log4js");

function Log(){

}

function log(type, code){

}

//用于debug调试信息
Log.prototype.debug = function(){

};

//用于记录有用的信息,例如花销什么的
Log.prototype.info = function(){

};

//用于提示警告信息
Log.prototype.warn = function(){

};

//用于提示错误信息,记录服务器的错误操作，以及
Log.prototype.error = function(){

};

moudle.exports = new Log();
