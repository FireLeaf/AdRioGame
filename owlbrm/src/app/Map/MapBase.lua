--
-- Author: Owl
-- Date: 2015-06-14 09:20:20
--
local MapBase = class("MapBase", function ()
	return display.newNode()
end)

function MapBase:ctor(inst_id)
	self.inst_id_ = inst_id
	self.piles_ = {}
end

function MapBase:LoadEntities()
	local inst_config = Instance_Config[self.inst_id_]
	if inst_config == nil then
		cclog("can't find instance: %d", self.inst_id_)
		return
	end
	self.entities_ = cc.uiloader:load(inst_config.base_ui_path .. ".csb")
	if self.entities_ == nil then
		cclog("load %s.csb failed", self.base_ui_path)
		return
	end
	self:addChild(self.entities_)

	
end

function MapBase:GetControl(name)
	return self.entities_ and self.entities_:getChildByName(name)
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