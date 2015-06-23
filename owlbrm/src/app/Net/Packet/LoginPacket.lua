--
-- Author: Owl
-- Date: 2015-06-14 08:14:50
--
SendPacket = SendPacket or {}

SendPacket.RegisterAccount = function (username, passwd, email)
	local data = {username = username, passwd = passwd, email = email}
	local packet = {id = SSC.REGISTER_ACCOUNT, data = data}
	HttpRequest:SendPostRequest(UrlGen(urlLoginRegister), packet)
end