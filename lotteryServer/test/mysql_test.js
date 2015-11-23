/**
 *Created by owlgame on 2015/11/22
 */
var mysqlController = require("../MySQLController.js").newController();

mysqlController.connect("127.0.0.1", "root", "");
mysqlController.query("use owlgame", function(error, result){
	console.log(result);	
});
mysqlController.query("insert into user (1234, \"ycqfsly@163.com\", \"owlgame\", \"yangcao123\")", function(error, result){});
mysqlController.query("select * form user", function(error, result){
	console.log(result);
});
