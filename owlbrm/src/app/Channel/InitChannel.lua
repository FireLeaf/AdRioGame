--
-- Author: Yangcao
-- Date: 2015-06-16 14:05:00
--
DEFAULT_CHANNEL			= 0

CHINA_CHANNEL 			= 10,
CHINA_APPSTORE_CHANNEL	= 11,


GameChannel = 
{
	[CHINA_CHANNEL] = import("app.Channel.ChannelBase"),
	[CHINA_APPSTORE_CHANNEL] = import(),
}
GameChannel.GetChannel() = function ( ... )
	if GameChannel.channel_ then
		return GameChannel.channel_
	end
	--return GameChannel[]
end