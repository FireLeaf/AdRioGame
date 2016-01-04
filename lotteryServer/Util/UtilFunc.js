/**
 * Created by Administrator on 2015/9/10.
 */
var fs = require('fs')

//����json�ļ���ʽ���ļ�
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

//���ĳ��ʱ�����ʱ���ַ�����ʾ ���������Ϊ�ձ�ʾ��ȡ��ǰ��ʱ��
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