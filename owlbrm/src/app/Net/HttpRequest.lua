--
-- Author: Owl
-- Date: 2015-06-14 08:06:06
--
local HttpRequest = class("HttpRequest")

function HttpRequest:ctor()
	-- body
end

function HttpRequest:SendPostRequest(url, data, handler, responseType)
	local http_post = cc.XMLHttpRequest:new()
	http_post.reponseType = responseType or cc.XMLHTTPREQUEST_RESPONSE_JSON
	http_post:open("POST", url)
	http_post:registerScriptHandler(function ()
		if type(handler) == "function" then
			hander(http_post)
		end
	end)
	http_post:send(data)
end

return HttpRequest