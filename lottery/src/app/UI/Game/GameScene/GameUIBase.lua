--
-- Author: OwlGame
-- Date: 2015-11-19 21:49:36
--
local GameUIBase = class("GameUIBase", function (...)
	return UIBase.new(...)
end)

function GameUIBase:base_ctor(cfg_name)
	print("GameUIBase ctor")
	self.room_cfg_ = game_room[cfg_name]
	if self.room_cfg_ == nil then
		return false
	end

	return true
end

function GameUIBase:base_init()
end

function GameUIBase:pos_retexture( key_pos, texture )
	local sprite = self:GetControl(key_pos)
	if sprite then
		sprite:setTexture(texture)
	end
end
return GameUIBase