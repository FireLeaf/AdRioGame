--
-- Author: Yangcao
-- Date: 2015-06-16 14:56:07
--
local InstanceBase = class("InstanceBase", function ()
	return display.newNode()
end)

function InstanceBase:ctor()

end

function InstanceBase:CreateInstance(inst_id)
	-- body
end

return InstanceBase