/**
 * Created by Administrator on 2015/9/10.
 */
var mysql = require('mysql');

function MySQLController()
{

}

MySQLController.prototype.connect = function(server, user, passwd){

};

MySQLController.prototype.query = function(queryInfo){

};

module.exports.newController = function()
{
    return new MySQLController();
};