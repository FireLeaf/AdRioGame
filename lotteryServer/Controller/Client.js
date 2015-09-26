/**
 * Created by Administrator on 2015/9/15.
 */

var Const = require("../Util/Const.js")

function LoginInfo(){
    this.login_type = Const.LOGIN_INVALID;
    this.user_name = "";
    this.user_passwd = "";
    this.user_token = "";

    this.verif_user_id = "";
    this.login_time_stamp = 0;
}

function Client(){
    this.uid = 0;
    this.session_id = "";
    this.last_time_stamp = 0;
    this.remote_address = "";
}

Client.prototype.refreshStatus = function(){
    //update time stamp
}

module.exports = Customer;