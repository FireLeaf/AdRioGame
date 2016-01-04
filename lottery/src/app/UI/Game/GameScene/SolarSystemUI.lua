--
-- Author: Yangcao
-- Date: 2015-10-12 20:56:52
--
local GameUIBase = import("app.UI.Game.GameScene.GameUIBase")
local ScratchCover = import("app.Game.ScratchCover")

local SolarSystemUI = class("SolarSystemUI", function (...)
	return GameUIBase.new(...)
end)

function SolarSystemUI:ctor()
	print("SolarSystemUI ctor")
	self:base_ctor("SolarSystem")

	self.mask_cover_ = nil
end

function SolarSystemUI:OnInit()
	self:base_init()

	local sprite_mask = self:GetControl("Sprite_Mask")
	local mx, my = sprite_mask:getPosition()
	local sz = sprite_mask:getContentSize()
	local parm = {width = sz.width, height = sz.height, x = sz.width / 2, y = sz.height / 2, print_file = "circle.png"}
	self.mask_cover_ = ScratchCover.new(parm)
	self.mask_cover_:AddSpriteToCover(sprite_mask, mx, my)
	sprite_mask:setVisible(false)

	self:addChild(self.mask_cover_)

	GlobalFunc.PrintLuaTable(self.room_cfg_)

	local key_poses = self.room_cfg_.key_pos
	local official_content = self.room_cfg_.official_content
	for i = 1, #key_poses do
		self:pos_retexture(key_poses[i], official_content[i].texture)
	end
end

return SolarSystemUI