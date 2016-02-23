
local MainScene = class("MainScene", function()
    return display.newScene("MainScene")
end)

local GameUICollection = import("app.UI.Game.GameUICollection")

function MainScene:ctor()
	self.uicollection = GameUICollection.new("GameUICollection")
	self:addChild(self.uicollection)

	self:scheduleUpdate()  
	self:addNodeEventListener(cc.NODE_ENTER_FRAME_EVENT, function(dt)  
       return self:Tick(dt)
	end)

	AudioEngine.playMusic("game_back.mp3")
end

function MainScene:Tick(dt)
	
end

--[[
function drawCircleNode(radius, params)
	local circle = display.newDrawNode()
	circle:drawCircle(radius, params)
	return circle
end

function MainScene:ctor()
	local back = display.newSprite("luckrabit/back.png")
	self:addChild(back)
	back:setPosition({x = display.width / 2, y = display.height / 2})
	local forgroud = display.newSprite("luckrabit/cover.png")

	--forgroud:setAnchorPoint(cc.p(0.0, 1.0))
	--self:addChild(forgroud)
	sz = forgroud:getContentSize()
	forgroud:setPosition({x = sz.width / 2, y = sz.height / 2})

	self.rtt = CCRenderTexture:create(sz.width, sz.height)
	print("width: " .. sz.width .. " height:" .. sz.height)
	self.rtt:begin()
	forgroud:visit()
	self.rtt:endToLua()
	--self.rtt:setAnchorPoint(cc.p(0.0, 1.0))
	self.rtt:setPosition({x = 668, y = 385})
	self:addChild(self.rtt)

	self.erase = display.newCircle(20, {color = cc.c4f(0, 0, 0, 0)})
	self.erase:setLineColor(cc.c4f(0, 0, 0, 0))
	self.erase:retain()

	self.fing_p = import("app.Game.FingerPrint.FingerPrint").new("circle.png")
	--self.fing_p:retain()
	self.rtt:setTouchEnabled(true)
	self.rtt:setTouchSwallowEnabled(false)
	self.rtt:addNodeEventListener(cc.NODE_TOUCH_EVENT, function (event)
		return self:onTouchEvent(event)
	end)
end

function MainScene:onTouchEvent( event )
	local x, y = event.x, event.y
	local px, py = self.rtt:getPosition()
	--local sz = self.rtt:getContentSize()
	print("touch event:" .. event.name)
	print("width : " .. sz.width .. " height : " .. sz.height)
	local bf = {}
	bf.src = GL_ONE
	bf.dst = GL_ZERO
	self.erase:setBlendFunc(bf)

	self.rtt:begin()
	self.erase:align(display.CENTER, x, y)
	--self.erase:visit()
	self.fing_p:Scratch(x - px + sz.width / 2, y - py + sz.height / 2)
	self.rtt:endToLua()
	return true
end
]]
function MainScene:onEnter()
end

function MainScene:onExit()
end

return MainScene
