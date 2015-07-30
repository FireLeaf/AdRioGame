--
-- Author: Yangcao
-- Date: 2015-07-30 14:23:11
-- 更新客户端资源
local UpdateScene = class("UpdateScene", function ()
	return display.newScene("UpdateScene")
end)

function UpdateScene:ctor()
	
end

function UpdateScene:onEnter()
	patcher.Start()--start patcher
	self:scheduleUpdate()  
	self:addNodeEventListener(cc.NODE_ENTER_FRAME_EVENT, function(dt)  
       return self:Tick(dt)
   end) 
end

function UpdateScene:Tick( dt )
	local status = patcher.GetStatus()
	if status.state == UPDATE_OK then
		app:enterScene("LoginScene")
	else if then

	end
end

function UpdateScene:onExit()
	
end

return UpdateScene