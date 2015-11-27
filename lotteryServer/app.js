/**
 * Created by Administrator on 2015/9/7.
 */
var http = require('http');
var util= require("./Util/util.js");
var netHandler = require("./NetHandler/NetHandler.js");
require("./test/mysql_test.js");
var conf = util.parserJsonFromFile("config.json");
console.log(conf);

var a={b:90,c:88};
for( var name in a)
    console.log(name);
console.log("fjdhfsahf" + 78);


http.createServer(function (req, res) {
    // 设置接收数据编码格式为 UTF-8
    req.setEncoding('utf-8');
    console.log(req.headers['x-forwarded-for']);
    console.log(req.connection.remoteAddress);
    console.log(req.socket.remoteAddress)
    netHandler.handlerHttpPacket(req, res);
    //console.log(req.connection.socket.remoteAddress);
//    var postData = ""; //POST & GET ： name=zzl&email=zzl@sina.com
//    // 数据块接收中
//    req.addListener("data", function (postDataChunk) {
//        postData += postDataChunk;
//    });
//    // 数据接收完毕，执行回调函数
//    req.addListener("end", function () {
//        console.log('数据接收完毕');
//        var params = JSON.parse(postData);//GET & POST  ////解释表单数据部分{name="zzl",email="zzl@sina.com"}
//        console.log(params);
//        console.log(params["id"]);
//        console.log(params["data"]);
//        res.writeHead(200, {
//            "Content-Type": "application/json;charset=utf-8"
//        });
//        var data = { id: 0, data: {
//            dir: 'kunhony',
//            param: 'archive' }
//        };
//        res.end(JSON.stringify(data));
//    });
}).listen(1338, '127.0.0.1');
console.log('Server running at http://127.0.0.1:1338/');
