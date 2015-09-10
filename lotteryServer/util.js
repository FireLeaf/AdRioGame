/**
 * Created by Administrator on 2015/9/10.
 */
var fs = require('fs')

exports.parserJsonFromFile = function(fileName){
    var configJson = {};
    try{
        var str = fs.readFileSync(fileName, "utf8");
        configJson = JSON.parser(str);
    }catch(e){
        console.log("parser " + fileName + " json failed!");
    }
    return configJson;
}