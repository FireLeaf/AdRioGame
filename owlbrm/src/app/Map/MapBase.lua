--
-- Author: Owl
-- Date: 2015-06-14 09:20:20
--
local MapBase = class("MapBase", function ()
	return display.newNode()
end)

function MapBase:ctor(mapname)
	self.mapname_ = mapname
	self.piles_ = {}
end

function MapBase:Init()
	
end

function MapBase:LoadMap()
	-- body
end

--触摸事件
function MapBase:OnTouchEvent(pile)
	
end

return MapBase