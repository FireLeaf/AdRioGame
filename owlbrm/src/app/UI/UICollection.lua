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

function UICollection:GetUI(uiname, vest)--ui文件名，以及创建的马甲名
    if uiname == nil then
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
		self.ui_inst_tbl_[uiname] = self.ui_inst_tbl_[uiname] or {}
		self.ui_inst_tbl_[uiname][nick] = ui
		ui:SetCollection(self)
		self:addChild(ui)
		ui:Show(false)
	end

	return ui
end

return UICollection