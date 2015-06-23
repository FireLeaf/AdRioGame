--
-- Author: Owl
-- Date: 2015-06-14 08:06:06
--
local HttpRequest = class("HttpRequest")

function HttpRequest:ctor()
	-- body
end

function HttpRequest:SendPostRequest(url, data, responseType)
	local http_post = cc.XMLHttpRequest:new()
	http_post.reponseType = responseType or cc.XMLHTTPREQUEST_RESPONSE_JSON
	http_post:open("POST", url)
	http_post:registerScriptHandler(function ()
		NetHandler:HanderHttp(http_post)
	end)
	local packet = json.encode(data)
	http_post:send(packet)
end

return HttpRequest