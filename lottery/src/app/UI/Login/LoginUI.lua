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

end

function LoginUI:OnInit()
	-- body
	self.btn_login_ = self:GetControl("Button_Login")
	self.btn_fblogin_ = self:GetControl("Button_FBLogin")
	--[[btnRegister:addTouchEventListener(function ( event )
		self:OnBtnRegister(event)
	end)]]
	self.btn_login_:addTouchEventListener(function ( sender, eventType )
		return self:OnBtnLogin(eventType)
	end)
end

function LoginUI:OnBtnLogin( event )
	--local x, y, prevX, prevY = event.x, event.y, event.prevX, event.prevY
	print(event)
	--[[print(event.name)
    if event.name == "began" then
         print("layer began")
    elseif event.name == "moved" then
        print("layer moved")
    elseif event.name == "ended" then
         print("layer ended")
    end]]
    if event == 2 then
    	SendPacket.RegisterAccount("yangcao", "yangcao123", "yangcao@163.com")
    	GlobalFunc.ReplaceScene("MainScene")
    end
    return true
end

function LoginUI:OnBtnRegister( event )
	local loginRegUI = self:GetUI("LoginRegUI")
	if loginRegUI then
		self:Show(false)
		loginRegUI:Show(true)
	end
end

return LoginUI