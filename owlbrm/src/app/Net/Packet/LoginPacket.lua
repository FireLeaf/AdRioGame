--
-- Author: Owl
-- Date: 2015-06-14 08:14:50
--
SendPacket = SendPacket or {}

SendPacket.RegisterAccount = function (username, passwd, email)
	local data = string.format("user_name = %s&passwd = %s&email = %s", username, passwd, email)
	HttpRequest:SendPostRequest(UrlGen(urlLoginRegister), data)
end