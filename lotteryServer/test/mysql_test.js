/**
 *Created by owlgame on 2015/11/22
 */
var mysqlController = require("../MySQLController.js").newController();
var util = require("util")

mysqlController.connect("127.0.0.1", "root", "");
mysqlController.query("use owlgame", function(error, result){
	console.log("use owlgame:" + result.toString());
});
mysqlController.query("insert into user values(123445, \"ycqfsly@163.com\", \"owlgame\", \"yangcao123\")", function(error, result) {
	if (error)
	{
		console.log("inset info:" + error.toString());
	}
	else
		console.log("insert info:" + result);
});

mysqlController.query(util.format("insert into user values(%d, \'%s\', \'%s\', \'%s\')", 897, "owlgame@163.com", "owlgame", "12345"), function(error, result) {
	if (error)
	{
		console.log("inset info:" + error.toString());
	}
	else
		console.log("insert info:" + result);
});

mysqlController.query("select * from user", function(error, result){
	console.log(result[0]);
});
