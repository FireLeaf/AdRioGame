/**
 * New node file
 */
var http = require("http");
var url = require("url");

function start(route, handle) {
  function onRequest(request, response) {
    var pathname = url.parse(request.url).pathname;
    console.log("Request for " + pathname + " received.");
    
    var postData = "";  
    //设置request请求的数据编码。  
    request.setEncoding("utf8");  
    request.addListener("data",function(data){  
        postData  += data;  
        console.log("Received POST data :") + data ;  
    });  
    request.addListener("end",function(){  
        route(handle,pathname,response,postData);  
    });
  }

  http.createServer(onRequest).listen(8080);
  console.log("Server has started.");
}

exports.start = start;

console.log('Server running at http://127.0.0.1:8080/');