/**
 * Created by Administrator on 2015/9/10.
 */
var fs = require('fs')

//解析json文件格式的文件
exports.parserJsonFromFile = function(fileName){
    var configJson = {};
    try{
        var str = fs.readFileSync(fileName, "utf8");
        configJson = JSON.parser(str);
    }catch(e){
        console.log("parser " + fileName + " json failed!");
    }
    return configJson;
};

//获得某个时间戳的时间字符串表示 ，如果传参为空表示获取当前的时间
exports.getDateTime = function(timestamp){
    var timeTmp = timestamp ? new Date(timestamp) : new Date();
    var yy = timeTmp.getFullYear();
    var mm = timeTmp.getMonth();
    var dd = timeTmp.getDate();

    mm === 0 ? mm = 12 : mm++;
    mm < 10 ? mm = '0'.concat(mm) : null;
    dd < 10 ? dd = '0'.concat(dd) : null;
    return '' + yy + mm + dd;
};