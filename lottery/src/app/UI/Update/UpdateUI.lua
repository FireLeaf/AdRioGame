--
-- Author: Yangcao
-- Date: 2015-08-17 21:37:50
--
local UpdateUI = class("UpdateUI", function (...)
	return UIBase.new(...)
end)

function UpdateUI:ctor()
	print("UpdateUI ctor")
	self:OnInit()
end

function UpdateUI:OnInit()
	local btnRetry = self:GetControl("Button_Retry")
	btnRetry:addTouchEventListener(function ( event )
		self:OnBtnRetry(event)
	end)
	self:OnBtnRetry()	
end

function UpdateUI:OnBtnRetry()
	XPatcher:GetInstance():StartPatch("http://127.0.0.1/patch_us/0.0.1/")--start patcher
end

function UpdateUI:OnTick(dt)
	local status = XPatcher:GetInstance():QueryPatcherState()
	
	if status.state == PS_NDS_ERROR then
		print("DNS resolve failed")
	elseif status.state == PS_FINISH then
		app:enterScene("LoginScene")
	end
end

return UpdateUI