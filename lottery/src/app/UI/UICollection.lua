--
-- Author: Owl
-- Date: 2015-06-12 22:54:17
--
local UICollection = class("UICollection", function ()
	return display.newNode()
end)

function UICollection:ctor(collection_name)
	-- body
	self.ui_class_tbl_ = {}
	self.ui_inst_tbl_ = {}
	self.ui_dsb_ = nil
	self.collection_name = collection_name
    print("ui collection ctor")
    if type(self.OnInit) == "function" then
		self:OnInit()
	end
end

function UICollection:AddTemplate(uiname, classname)
	self.ui_class_tbl_[uiname] = classname
    print("register " .. uiname )
end

function UICollection:release()
	self.ui_class_tbl_ = nil
	self.ui_inst_tbl_ = nil
end

function UICollection:GetName( )
	return self.collection_name
end

function UICollection:PeekUI(uiname, vest)
	local nick = vest or uiname
	if uiname and self.ui_inst_tbl_[uiname] ~= nil then
		return self.ui_inst_tbl_[uiname][nick]
	end
	return nil
end

function UICollection:Tick(dt)
	for class_name, inst_table in pairs(self.ui_inst_tbl_) do
		for i_t, inst in pairs(inst_table) do
			if inst ~= nil and inst:IsShow() then
				inst:OnTick(dt)
			end
		end
	end
end

function UICollection:AlignUI(ui, align)
	if ui == nil or align == nil then
		return
	end

	local posx, posy = ui:getPosition()
	local anchor = ui:getAnchorPoint()
	local sz = ui:getContentSize()
	print(ui:getName() .. " Pos : (" .. posx .. "," .. posy .. ") Anchor : (" .. anchor.x .. "," .. anchor.y .. ") ContentSZ : (" .. sz.width .. "," .. sz.height .. ")")

	if align.xalign == -1 then
	elseif align.xalign == 0 then
	elseif align.xalign == 1 then
	else
	end

	if align.xalign == -1 then

	elseif align.xalign == 0 then
		--ui:setAnchorPoint(cc.p(0, 0.5))
		ui:setPositionY(53)
		local posx, posy = ui:getPosition()
		local anchor = ui:getAnchorPoint()
		print(ui:getName() .. " Pos : (" .. posx .. "," .. posy .. ") Anchor : (" .. anchor.x .. "," .. anchor.y .. ")")
	elseif align.xalign == 1 then

	else

	end
end

function UICollection:GetUI(uiname, vest)--ui文件名，以及创建的马甲名
    if uiname == nil or self.ui_dsb_ == nil or self.ui_dsb_[uiname] == nil then
        return nil
    end
    local ui = self:PeekUI(uiname, vest)
	if ui then
		return ui
	end
    print("creat ui : " .. uiname)
    local nick = vest or uiname
	local uiclass = self.ui_class_tbl_[uiname]
	if uiclass then
		ui = uiclass.new(uiname, nick)
	else
        print("unkonw ui :", uiname)
		ui = UIBase.new(uiname, nick)
	end

	if ui then
		if type(ui.OnInit) == "function" then
			ui:OnInit()
		end
		self.ui_inst_tbl_[uiname] = self.ui_inst_tbl_[uiname] or {}
		self.ui_inst_tbl_[uiname][nick] = ui
		ui:SetCollection(self)
		self:addChild(ui)
		self:AlignUI(ui, self.ui_dsb_[uiname])
		ui:setVisible(false)
	end

	return ui
end

return UICollection