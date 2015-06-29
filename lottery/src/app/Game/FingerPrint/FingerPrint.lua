--
-- Author: Owl
-- Date: 2015-06-28 11:25:27
--

local FingerPrint = class("FingerPrint")

function FingerPrint:ctor(print_file, param)
	self.print_ = display.newSprite("fingerprint/" .. print_file)
	self.print_:retain()
	self.print_:getTexture():setAliasTexParameters()
	local bf = {}
	bf.src = GL_ONE_MINUS_SRC_ALPHA
	bf.dst = GL_SRC_ALPHA
	self.print_:setBlendFunc(bf)
end

function FingerPrint:Scratch(x, y)
	self.print_:setPosition(x, y)
	self.print_:visit()
end

return FingerPrint