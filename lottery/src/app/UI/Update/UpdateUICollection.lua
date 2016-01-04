--
-- Author: Yangcao
-- Date: 2015-08-17 21:44:48
--
local UpdateUICollection = class("UpdateUICollection", function ()
	return UICollection.new("Update_Collection")
end)

local UpdateUI = import("app.UI.Update.UpdateUI")
import("app.UI.Update.UpdateDsb")

function UpdateUICollection:ctor()
    print("UpdateUICollection:ctor")
    self:OnInit()
end

function UpdateUICollection:OnInit()

	self.ui_dsb_ = UpdateUIDsb

    print("Login UI Collection Init")
    self:AddTemplate("UpdateUI", UpdateUI)

    local updateUI = self:GetUI("UpdateUI")
    if updateUI then
    	updateUI:Show(true)
    end
end

return UpdateUICollection