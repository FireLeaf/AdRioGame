--
-- Author: Yangcao
-- Date: 2015-08-17 21:37:50
--
local UpdateUI = class("UpdateUI", function (...)
	return UIBase.new(...)
end)

function UpdateUI:ctor()
	print("UpdateUI ctor")
	self.lab_cur_version_ = nil
	self.lab_tar_version_ = nil
	self.lab_cur_progress_ = nil
	self.progress_update_ = nil
	self.lab_cur_status_= nil
	self.btn_retry_ = nil
	self.counter_ = nil
	self.is_enter_scene_ = false
end

function UpdateUI:OnInit()
	print("UpdateUI:OnInit")
	self.lab_cur_version_ = self:GetControl("Text_CurVersion")
	self.lab_tar_version_ = self:GetControl("Text_LastestVersion")
	self.lab_cur_progress_ = self:GetControl("Text_CurProgress")
	self.progress_update_ = self:GetControl("Progress_Update")
	self.lab_cur_status_ = self:GetControl("Text_CurStatus")
	self.btn_retry_ = self:GetControl("Button_Retry")
	self.btn_retry_:addTouchEventListener(function ( event )
		self:OnBtnRetry(event)
	end)
	self.btn_retry_:setVisible(false);
	self:StartPatch()
end

function UpdateUI:OnShow()
	self.is_enter_scene_ = false
	print("UpdateUI:OnShow")
end

function UpdateUI:StartPatch()
	XPatcher:GetInstance():StartPatch("http://127.0.0.1/patch_us/0.0.1/")--start patcher	
end

function UpdateUI:OnBtnRetry()
	self:StartPatch()
end

function UpdateUI:OnTick(dt)
	local status = XPatcher:GetInstance():QueryPatcherState()
	local state = status.state
	local cur_version_string = math.ceil(status.cur_version.main_version) .. "." .. math.ceil(status.cur_version.sub_version) .. "." .. math.ceil(status.cur_version.asset_version)
	local tar_version_string = math.ceil(status.target_version.main_version) .. "." .. math.ceil(status.target_version.sub_version) .. "." .. math.ceil(status.target_version.asset_version)
	local status_string = ""
	local progress_string = "0%"
	local progress = 0
	if state == PS_START then
		status_string = StringTable.GetString("PATCHER_STARTING")
		progress = 100
	elseif state == PS_CHECK_NETOWRK then
		status_string = StringTable.GetString("PATCHER_CHECK_NETWORK")
		progress = 100
	elseif state == PS_CHECK_VERSION then
		status_string = StringTable.GetString("PATCHER_CHECK_VERSION")
		progress = 100
	elseif state == PS_DOWNLOAD_PATCH then
		status_string = StringTable.GetString("PATCHER_DOWNLOAD_PATCH")
		progress = math.ceil((status.getted_length / status.total_length) * 100)
		progress_string =  progress .. "%(" .. math.ceil(status.getted_length / 1024) .. "KB/" .. math.ceil(status.total_length / 1024) .."KB)"
	elseif state == PS_APPLY_PATCH then
		status_string = StringTable.GetString("PATCHER_APPLAY_PATCH")
	elseif state == PS_FINISH then
		progress = 100
		status_string = StringTable.GetString("PATCHER_FINISH")
		if self.is_enter_scene_ == false then
			print("replace to login scene")
			self.is_enter_scene_ = true
			GlobalFunc.ReplaceScene("LoginScene")
		end
	elseif state == PS_UNKONW then
	elseif state == PS_NDS_ERROR then
		status_string = StringTable.GetString("PATCHER_DNS_ERROR")
	elseif state == PS_LOCAL_ASSET_BROKEN then
		status_string = StringTable.GetString("PATCHER_LOCAL_ASSET_BROKEN")
	elseif state == PS_ASSET_BROKEN then
		status_string = StringTable.GetString("PATCHER_ASSET_BROKEN")
	elseif state == PS_NETWORK_EXCEPTION then
		status_string = StringTable.GetString("PATCHER_NETWORK_EXCEPTION")
	elseif state ==  PS_APPVER_ERROR then
		status_string = StringTable.GetString("PATCHER_APPVER_ERROR")
	elseif state == PS_PATCH_ERROR then
		status_string = StringTable.GetString("PATCHER_PATCH_ERROR")
	end

	self.lab_cur_version_:setString(cur_version_string)
	self.lab_tar_version_:setString(tar_version_string)
	self.btn_retry_:setVisible(state >= PS_UNKONW )
	self.lab_cur_status_:setString(status_string)
	self.lab_cur_progress_:setString(progress_string)
	self.progress_update_:setPercent(progress)
end

return UpdateUI