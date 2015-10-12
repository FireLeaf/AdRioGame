--
-- Author: Yangcao
-- Date: 2015-10-08 23:22:57
--
local GameUICollection = class("GameUICollection", function ()
	return UICollection.new("Game_Collection")
end)

import("app.UI.Game.GameDsb")

local GameMainUI = import("app.ui.Game.GameMain")
local SolarSystem = import("app.UI.Game.GameScene.SolarSystemUI")

function GameUICollection:ctor()
    print("GameUICollection:ctor")
    self:OnInit()
end

function GameUICollection:OnInit()
    self.ui_dsb_ = GameUIDsb

    self:AddTemplate("GameMain", GameMainUI)
    self:AddTemplate("SorlarSystem/SolarSystemScene", SolarSystem)
    print("Game UI Collection Init")

    local gameMainUI = self:GetUI("GameMain")
    if gameMainUI then
    	gameMainUI:Show(true)
    end
end

return GameUICollection