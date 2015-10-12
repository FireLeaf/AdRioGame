--
-- Author: Yangcao
-- Date: 2015-10-12 21:24:33
--
local GameMainUI = class("GameMainUI", function (...)
	return UIBase.new(...)
end)

function GameMainUI:ctor()
	print("GameMainUI ctor")

end

function GameMainUI:OnInit()
end

return GameMainUI