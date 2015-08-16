--
-- Author: Owl
-- Date: 2015-06-12 23:24:43
--
local LoginUI = class("LoginUI", function (...)
	return UIBase.new(...)
end)

function LoginUI:ctor()
	print("LoginUI ctor")
	self:OnInit()
end

function LoginUI:OnInit()
	-- body
	local btnLogin = self.ui_:getChildByName("Button_Login")
	local btnRegister = self:GetControl("Button_Register")
	btnRegister:addTouchEventListener(function ( event )
		self:OnBtnRegister(event)
	end)
end

function LoginUI:OnBtnRegister( event )
	local loginRegUI = self:GetUI("LoginRegUI")
	if loginRegUI then
		self:Show(false)
		loginRegUI:Show(true)
	end
end

return LoginUI