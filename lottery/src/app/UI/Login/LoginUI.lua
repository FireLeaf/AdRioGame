--
-- Author: Owl
-- Date: 2015-06-12 23:24:43
--
local LoginUI = class("LoginUI", function (...)
	return UIBase.new(...)
end)

function LoginUI:ctor()
	print("LoginUI ctor")

	self.btn_login_ = nil
	self.btn_fblogin_ = nil

	self:OnInit()
end

function LoginUI:OnInit()
	-- body
	self.btn_login_ = self:GetControl("Button_Login")
	self.btn_fblogin_ = self:GetControl("Button_FBLogin")
	--[[btnRegister:addTouchEventListener(function ( event )
		self:OnBtnRegister(event)
	end)]]
end

function LoginUI:OnBtnRegister( event )
	local loginRegUI = self:GetUI("LoginRegUI")
	if loginRegUI then
		self:Show(false)
		loginRegUI:Show(true)
	end
end

return LoginUI