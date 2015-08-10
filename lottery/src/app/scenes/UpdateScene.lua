--
-- Author: Yangcao
-- Date: 2015-07-30 14:23:11
-- 更新客户端资源
local UpdateScene = class("UpdateScene", function ()
	return display.newScene("UpdateScene")
end)

function UpdateScene:ctor()
	local back = display.newSprite("patch_background.jpg")
	self:addChild(back)
	back:setPosition({x = display.width / 2, y = display.height / 2})
end

function UpdateScene:onEnter()
	XPatcher:GetInstance():StartPatch("http://127.0.0.1/patch_us/0.0.1/")--start patcher
	self:scheduleUpdate()  
	self:addNodeEventListener(cc.NODE_ENTER_FRAME_EVENT, function(dt)  
       return self:Tick(dt)
   end) 
end

function UpdateScene:Tick( dt )
	local status = XPatcher:GetInstance():QueryPatcherState()
	if status.state == PS_FINISH then
		app:enterScene("LoginScene")
	end
end

function UpdateScene:onExit()
	
end

return UpdateScene