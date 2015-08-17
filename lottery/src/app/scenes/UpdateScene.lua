--
-- Author: Yangcao
-- Date: 2015-07-30 14:23:11
-- 更新客户端资源
local UpdateScene = class("UpdateScene", function ()
	return display.newScene("UpdateScene")
end)

local UpdateUICollection = import("app.UI.Update.UpdateUICollection")

function UpdateScene:ctor()
	--[[local back = display.newSprite("patch_background.jpg")
	self:addChild(back)
	back:setPosition({x = display.width / 2, y = display.height / 2})
	]]
	self.uicollection = UpdateUICollection.new("UpdateUICollection")
	self:addChild(self.uicollection)
end

function UpdateScene:onEnter()
	self:scheduleUpdate()  
	self:addNodeEventListener(cc.NODE_ENTER_FRAME_EVENT, function(dt)  
       return self:Tick(dt)
   end) 
end

function UpdateScene:Tick( dt )
	if self.uicollection then
		self.uicollection:Tick(dt)
	end
end

function UpdateScene:onExit()
	
end

return UpdateScene