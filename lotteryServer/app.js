/**
 * Created by Administrator on 2015/9/7.
 */
var http = require('http');
var util= require("./util.js");
var mysqlController = require("./MySQLController.js");
var controller = mysqlController.newController();
var conf = util.parserJsonFromFile("config.json");
console.log(conf);

http.createServer(function (req, res) {
    // 设置接收数据编码格式为 UTF-8
    req.setEncoding('utf-8');
    var postData = ""; //POST & GET ： name=zzl&email=zzl@sina.com
    // 数据块接收中
    req.addListener("data", function (postDataChunk) {
        postData += postDataChunk;
    });
    // 数据接收完毕，执行回调函数
    req.addListener("end", function () {
        console.log('数据接收完毕');
        var params = JSON.parse(postData);//GET & POST  ////解释表单数据部分{name="zzl",email="zzl@sina.com"}
        console.log(params);
        console.log(params["id"]);
        console.log(params["data"]);
        res.writeHead(200, {
            "Content-Type": "application/json;charset=utf-8"
        });
        var data = { id: 0, data: {
            dir: 'kunhony',
            param: 'archive' }
        };
        res.end(JSON.stringify(data));
    });
}).listen(1338, '192.168.199.184');
console.log('Server running at http://192.168.199.184:1338/');