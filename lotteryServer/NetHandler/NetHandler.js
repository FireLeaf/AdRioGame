/**
 * Created by pc on 2015/9/14.
 */

require("./NetCode.js");
var loginHandler = require("./LoginHandler.js");

var handlerPool = {};
function registerHandler(code, responseHandler){
    handlerPool[code] = responseHandler;
}

loginHandler.RegisterHandler(registerHandler);

exports.handlerHttpPacket = function (req, res) {
    // 设置接收数据编码格式为 UTF-8
    req.setEncoding('utf-8');
    var postData = ""; //POST & GET ： name=zzl&email=zzl@sina.com
    // 数据块接收中
    req.addListener("data", function (postDataChunk) {
        postData += postDataChunk;
        if (postData.length > 16384){
            res.writeHead(414 );
            res.end();
        }
    });
    // 数据接收完毕，执行回调函数
    req.addListener("end", function () {
        console.log('数据接收完毕');
        try{
            var params = JSON.parse(postData);//GET & POST  ////解释表单数据部分{name="zzl",email="zzl@sina.com"}
            if(params["id"] != null && params["data"] != null)// && params["session_id"] != null)
            {
                if(handlerPool[params["id"]] != null)
                {
                    handlerPool[params["id"]](req, res, params);
                }
            }
            else
            {
                //...
            }
        }catch(exp){
            //...
        }


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
    });
};