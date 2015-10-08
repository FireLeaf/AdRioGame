--
-- Author: Yangcao
-- Date: 2015-10-08 23:22:57
--
local GameUICollection = class("GameUICollection", function ()
	return UICollection.new("Game_Collection")
end)

import("app.UI.Game.GameDsb")

function GameUICollection:ctor()
    print("GameUICollection:ctor")
    self:OnInit()
end

function GameUICollection:OnInit()
    self.ui_dsb_ = GameUIDsb

    print("Game UI Collection Init")
end

return LoginUICollection