--
-- Author: Owl
-- Date: 2015-06-12 23:49:22
--
local LoginRegUI = class("LoginRegUI", function (...)
	return UIBase.new(...)
end)

function LoginRegUI:ctor( ... )
	print("Login Reg UI ctor")
	self:OnInit()
end

function LoginRegUI:OnInit()
	local okBtn = self:GetControl("Button_OK")
	if okBtn then
		okBtn:addTouchEventListener(function (event)
			self:OnBtnOK()
		end)
	end
	local cancelBtn = self:GetControl("Button_Cancel")
	if cancelBtn then
		cancelBtn:addTouchEventListener(function (event)
			self:OnBtnCancel(event)
		end)
	else
		print("cant find cancel")
	end
end

function LoginRegUI:OnBtnCancel( event )
	print("btn cancel")
	self:SwitchToShowUI("LoginUI")
end

function LoginRegUI:OnBtnOK( event )
	local userName = self:GetControl("TextField_UserName")
	local passwd = self:GetControl("TextField_PassWd")
	local passwd_again = self:GetControl("TextField_PassWd_Confirm")
	local email = self:GetControl("TextField_eMail")
	print("userName:" .. userName:getString())
	if passwd:getString() ~= passwd_again:getString() then
		print("passwd unmatch")
		return
	end
	SendPacket.RegisterAccount(userName:getString(), passwd:getString(), email:getString())
	--[[local http_post = cc.XMLHttpRequest:new()
	local data = string.format("user_name = %s&passwd = %s&email = %s", userName:getString(), passwd:getString(), email:getString())
	http_post.reponseType = cc.XMLHTTPREQUEST_RESPONSE_JSON
	http_post:open("POST", "http://192.168.199.163:8080/register")
	http_post:registerScriptHandler(function ( )
		if http_post.readStata == 4 then
			print("....")
		end
	end)
	http_post:send(data)]]
end

return LoginRegUI