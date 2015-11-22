--
-- Author: Yangcao
-- Date: 2015-10-12 21:24:33
--
local GameMainUI = class("GameMainUI", function (...)
	return UIBase.new(...)
end)

function GameMainUI:ctor()
	print("GameMainUI ctor")

end

function GameMainUI:OnInit()
	--[[local game_item_list = self:GetControl("ListView_1")
	for i = 1, 5 do
		--local item = game_item_list:newItem()
		local content = cc.ui.UIPushButton.new("owl_room_entry.png")
			:setButtonSize(600, 64)
			:setButtonLabel(cc.ui.UILabel.new({text = "explorer solarsytem", size = 48, color = display.COLOR_RED}))
			:onButtonClicked(function ( event )
				
			end)
		--item:addContent(content)
		--item:setItemSize(600, 64)

		--game_item_list:addItem(item)
		game_item_list:pushBackCustomItem(content)
	end
	]]
	--game_item_list:reload()
	local room_list = self:GetControl("ListView_Info")
	if room_list then
		room_list:setTouchEnabled(true)
		local list_item = room_list:getChildByName("ListItem")
		local lab_name = list_item:getChildByName("Text_RomName")
		lab_name:setString("太阳系的奇迹")
		local btn_join = list_item:getChildByName("Button_2")
		if btn_join then
			print("have btn_join")
		end
		btn_join:addTouchEventListener(function ( sender, eventType )
			return self:OnBtnJoin(sender, eventType)
		end)
	end
end

function GameMainUI:OnBtnJoin( sender, eventType )
	print(eventType)
	if eventType == 2 then
    	self:SwitchToShowUI("SolarSystemUI")
    end
    return true
end

return GameMainUI