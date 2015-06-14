/**
 * New node file
 */
var http = require('http');
var url = require('url');
var util = require('util');

function route(handle,pathname,response,postData) {
  console.log("About to route a request for " + pathname);
  if(pathname == "/login"){
  	var user = require('./usermanage/user');
  	users = new user(response);
  	var selectSql = 'SELECT userid FROM users where username = \'test01\' and password = \'test01\'';
  	users.checkuser(selectSql);
  }
  if(pathname == "/register"){
	  var user = require('./usermanage/user');
	  users = new user(response);
	  console.log(postData);
	  response.end(postData);
  }
}

exports.route = route;