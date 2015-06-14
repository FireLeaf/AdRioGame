--
-- Author: Owl
-- Date: 2015-05-28 20:48:42
--
local LoginScene = class("LoginScene", function() 
	return display.newScene("LoginScene")
end)

local LoginUICollection = import("app.UI.Login.LoginUICollection")

function LoginScene:ctor()
	self.uicollection = LoginUICollection.new("LoginUICollection")
	self:addChild(self.uicollection)
end

function LoginScene:onEnter()
	local loginui = self.uicollection:GetUI("LoginUI")
	if loginui then
		loginui:Show(true)
	end
end

function LoginScene:onExit()
	-- body
	self.uicollection:release()
	self.uicoolection = nil
end

return LoginScene