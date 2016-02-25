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

function UIBase:GetUIName()
	return self.uifile_
end

function UIBase:GetVestName()
	return self.vest_
end

function UIBase:LoadUI()
	-- body
	--cc.FileUtils:getInstance():addSearchPath("res/" .. self.uifile_ .. "/")
	local csbfile = self.uifile_ .. ".csb"
	local jsonfile = self.uifile_ .. ".json"
	local uifile
	if cc.FileUtils:getInstance():isFileExist(csbfile) then
		uifile = csbfile
	elseif cc.FileUtils:getInstance():isFileExist(jsonfile) then
		uifile = jsonfile
	end
	if uifile then
		self.ui_ = cc.uiloader:load(uifile)--:addTo(self)
		if self.ui_ then
			print("load" .. uifile .. " successful")
			local sz = self.ui_:getContentSize()
			print("sz.x:" .. sz.width .. ",sz.y" .. sz.height)
		else
			print("load" .. uifile .. " failed")
		end
	else
		print("cannot find ui: " .. self.uifile_)
	end
	
	--print("x : " .. ui:getPositionX() .. " y : " .. ui:getPositionY())
	

	self:addChild(self.ui_)
end

function UIBase:GetControl(name)
	return self.ui_ and self.ui_:getChildByName(name)
end

function UIBase:GetDialogSize()
	local dialog_frame = self:GetControl("Dialog_Frame")
	if dialog_frame then
		local sz = dialog_frame:getContentSize()
		return sz.width, sz.height
	end
	local sz = self.ui_:getContentSize()
	return sz.width, sz.height
end

function UIBase:Show(show_ui)
	local is_visable = self:isVisible()
	self:setVisible(show_ui)
	if show_ui ~= is_visable then
		if show_ui and type(self.OnShow) == "function" then
			self:OnShow()
		elseif show_ui == false and type(self.OnHide) == "function" then
			self:OnHide()
		end
	end
end

function UIBase:IsShow()
	return self:isVisible()
end

function UIBase:OnTick(dt)

end

function UIBase:SwitchToShowUI(name)
	local other = self:GetUI(name)
	if other then
		print("switch to :" ..  name)
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