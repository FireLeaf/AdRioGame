--
-- Author: Owl
-- Date: 2015-06-28 10:44:51
--

local FingerPrint = import("app.Game.FingerPrint.FingerPrint")

local ScratchCover = class("ScratchCover", function (parm)
	GlobalFunc.PrintLuaTable(parm)
	return CCRenderTexture:create(parm.width, parm.height)
end)

function ScratchCover:ctor(parm)
	self.sz_ = {width = parm.width, height = parm.height,}
	self.finger_ = FingerPrint.new(parm.print_file)
	self:setPosition(parm.x, parm.y)
	self:setTouchEnabled(true)
	self:setTouchSwallowEnabled(false)
	self:addNodeEventListener(cc.NODE_TOUCH_EVENT, function ( event )
		return self:onTouchEvent(event)
	end)
end

function ScratchCover:AddTextureToCover( cover_file, x, y)
	local sprite = display.newSprite(cover_file)
	if sprite == nil then
		print("add cover failed:" .. cover_file)
		return false
	end
	self:AddSpriteToCover(sprite, x, y)
end

function ScratchCover:AddSpriteToCover( sprite, x, y)
	self:begin()
	sprite:setPosition(x, y)
	sprite:visit()
	self:endToLua()
end

function ScratchCover:SetFinger(finger)
	self.finger_ = FingerPrint.new(print_file) 
end

function ScratchCover:PrintFinger(finger, x, y)
	finger:Scratch(x, y)
end

function ScratchCover:onTouchEvent( event )
	local x, y = event.x, event.y
	local px, py = self:getPosition()
	local ppx, ppy = self:getParent():getPosition()
	print("touch (x:" .. x .. ",y:" .. y.. "); pos (px:" .. px .. ",py:" .. py .. "); size (sx:" .. self.sz_.width / 2 .. ", sy:" .. self.sz_.height / 2 .. ")")
	self:begin()
	self.finger_:Scratch(x - px - ppx + self.sz_.width / 2, y - py - ppy + self.sz_.height / 2 )
	self:endToLua()
	return true
end

return ScratchCover