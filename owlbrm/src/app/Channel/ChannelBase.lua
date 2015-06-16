--
-- Author: Yangcao
-- Date: 2015-06-16 11:34:23
--
local ChannelBase = class("ChannelBase")

function ChannelBase:ctor(channel_id)
	self.channel_id_ = channel_id
end

function ChannelBase:Login(user_name, passwd)
	return false	
end

function ChannelBase:Buy( ... )
	-- body
end

function ChannelBase:LoginRe( ... )
	-- body
end

return ChannelBase