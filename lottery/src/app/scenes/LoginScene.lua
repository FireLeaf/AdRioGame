--
-- Author: Yangcao
-- Date: 2015-07-30 15:04:17
--
local LoginScene = class("LoginScene", function (  )
	return display.newScene("LoginScene")
end)

local LoginUICollection = import("app.UI.Login.LoginUICollection")

function LoginScene:ctor()
	self.uicollection = LoginUICollection.new("LoginUICollection")
	self:addChild(self.uicollection)
end

function LoginScene:LoadLocalLogInfo()
	
end

function LoginScene:onEnter()
	
end

function LoginScene:onExit()
	
end

return LoginScene