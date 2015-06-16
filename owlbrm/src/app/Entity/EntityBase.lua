--
-- Author: Owl
-- Date: 2015-06-14 09:26:42
--
local EntityBase = class("EntityBase", function ()
	return display.newSprite()
end)

function EntityBase:ctor(id)
	self.id_ = id
	self.body_ = nil
	self.hat_ = nil
	self.glass_ = nil
end

function EntityBase:MoveTo()
	cc.Sequence()
end

--执行一步
function EntityBase:MoveStep()
	-- body
end

--形象设置

--身体
function EntityBase:UpdateBody( ... )
	-- body
end

function EntityBase:PlayAnimation()
	-- body
end

return EntityBase