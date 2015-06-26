--
-- Author: Yangcao
-- Date: 2015-06-25 10:26:58
--
local HttpDownload = class("HttpDownload")

function HttpDownload:ctor()
	
end

function HttpDownload:Download( )
	local request = network.createHTTPRequest(function ( event )
		event.request:saveResponseData("D:\\mucai.bmp")
	end, "http://127.0.0.1/fileres/mucai.bmp", "POST")
end

return HttpDownload