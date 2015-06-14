/**
 * New node file
 */
var http = require('http');
var util = require('util');
var sqlClient = require('../database/dataserver');

function user(response){
	var test = new sqlClient(response);
	this.checkuser = function(querySql){
	    var res = test.query(querySql);
	    console.log(res);
	}
	
	this.getuser = function(username){
		var sql = "SELECT userid from users where username = '" + username + "'";
		var res = test.query(querySql);
		console.log(res);
	}
	
	this.passwordMd5 = function(password){
		
	}
}

module.exports = user;