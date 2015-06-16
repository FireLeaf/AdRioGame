--
-- Author: Yangcao
-- Date: 2015-06-16 15:00:53
--
local MiniGameBase = class("MiniGameBase", function ()
	return display.newNode()
end)

function MiniGameBase:ctor()
	
end

function MiniGameBase:EnterGame()
	-- body
end

function MiniGameBase:LeaveGame()
	-- body
end

return MiniGameBase