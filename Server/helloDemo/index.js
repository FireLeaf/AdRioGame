/**
 * New node file
 */
var server = require("./server");
var router = require("./router");

server.start(router.route);