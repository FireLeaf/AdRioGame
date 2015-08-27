--
-- Author: Owl
-- Date: 2015-06-13 15:58:37
--
local WaitForUI = class("WaitForUI", function ( ... )
	return UIBase.new(...)
end)

function WaitForUI:ctor( ... )
	self:OnInit()
end

function WaitForUI:OnInit()

end

return WaitForUI