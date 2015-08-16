--
-- Author: Yangcao
-- Date: 2015-06-16 15:18:45
--
local LoadingUI = class("LoadingUI", function ( ... )
	return UIBase.new(...)
end)

function LoadingUI:ctor( ... )
	self:OnInit()
end

function LoadingUI:OnInit()

end

function LoadingUI:SetProgress(progress)
	
end

return LoadingUI