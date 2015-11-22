/**
 * Created by Administrator on 2015/9/10.
 */
var mysql = require('mysql');

function MySQLController()
{
    this.connection = null;
}

MySQLController.prototype.connect = function(server, user_name, passwd){
    this.connection = mysql.createConnection(
        {
            host : server,
            user : user_name,
            password : passwd,
        }
    );
};

MySQLController.prototype.disconnect = function(){
    if ( is_connected() ){
        this.connection.end(function(err){
            console.warn(err);
        });
    }
}

MySQLController.prototype.is_connected = function(){
    return (this.connection != null) && this.connection.connect(function(err){
            console.warn(err);
        });
}

//callback func(error, reult)
MySQLController.prototype.query = function(queryInfo, callback){
    if ( is_connected() ){
        this.connection.query(queryInfo, callback);
    }
    else {

    }
};



module.exports.newController = function()
{
    return new MySQLController();
};