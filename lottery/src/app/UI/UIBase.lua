--
-- Author: Owl
-- Date: 2015-06-12 22:42:37
--
local UIBase = class("UIBase", function ()
	local node = display.newNode()
	return node
end)

function UIBase:ctor(uifile, vest)
	-- body
	self.uifile_ = uifile
	self.vest_ = vest
	self:LoadUI()
	if type(self.OnInit) == "function" then
		self:OnInit()
	end
end

function UIBase:LoadUI()
	-- body
	self.ui_ = cc.uiloader:load(self.uifile_ .. ".csb")--:addTo(self)
	--print("x : " .. ui:getPositionX() .. " y : " .. ui:getPositionY())
	self:addChild(self.ui_)
end

function UIBase:GetControl(name)
	return self.ui_ and self.ui_:getChildByName(name)
end

function UIBase:Show(show_ui)
	local is_visable = self:isVisible()
	if is_visable then
		--todo
	end
	self:setVisible(show_ui)
end

function UIBase:SwitchToShowUI(name)
	print("switch to :" ..  name)
	local other = self:GetUI(name)
	if other then
		self:Show(false)
		other:Show(true)
	end
end

function UIBase:SetCollection(collection)
	self.collection_ = collection
end

function UIBase:GetUI(name, vest)
	return self.collection_ and self.collection_:GetUI(name, vest)
end

return UIBase