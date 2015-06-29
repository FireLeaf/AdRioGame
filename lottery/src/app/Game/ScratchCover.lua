--
-- Author: Owl
-- Date: 2015-06-28 10:44:51
--
local ScratchCover = class("ScratchCover", function (width, height, ...)
	return CCRenderTexture:create(width, height)
end)

function ScratchCover:ctor(width, height, x, y, print_file)
	self.finger_print_ = FingerPrint.new(print_file)
	self:setPosition(x, y)
end

function ScratchCover:AddBackground( ground_file )
	
end

return ScratchCover