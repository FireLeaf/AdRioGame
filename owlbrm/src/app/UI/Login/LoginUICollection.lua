--
-- Author: Owl
-- Date: 2015-06-13 09:50:48
--
local LoginUICollection = class("LoginUICollection", function ()
	return UICollection.new("Login_Collection")
end)

local LoginUI = import("app.UI.Login.LoginUI")
local LoginRegUI = import("app.UI.Login.LoginRegUI")

function LoginUICollection:ctor()
    print("LoginUICollection:ctor")
    self:OnInit()
end

function LoginUICollection:OnInit()
    print("Login UI Collection Init")
    self:AddTemplate("LoginUI", LoginUI)
	self:AddTemplate("LoginRegUI", LoginRegUI)
end

return LoginUICollection