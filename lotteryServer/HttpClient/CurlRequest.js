/**
 * Created by Administrator on 2015/9/17.
 */
var request = require('request');
var querystring = require('querystring');

function CurlRequest(){

}

CurlRequest.prototype.CurlGet = function(url, get, handler){
    assert(url != null, get != null, typeof(handler) == "function");
    if (get){
        url += (url.indexOf('?') > -1) ? '&' : '?';
    }
    url = encodeURI(url + querystring.stringify(get));

    var params = {};
    params['url'] = url;
    params['json'] = true;
    request.get(params, function(error, response, result){
            handler(error, response, result);
    });
};

CurlRequest.prototype.CurlPost = function(url, post, handler){
    assert(url != null, post != null, typeof(handler) == "function");
    var params = {};
    params['url'] = url;
    params['json'] = true;
    params['form'] = post;
    request.post(params, function(error, response, result){
       handler(error, response, result);
    });
};

module.exports = new CurlRequest();