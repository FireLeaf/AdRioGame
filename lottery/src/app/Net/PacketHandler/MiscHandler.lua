--
-- Author: Yangcao
-- Date: 2015-06-23 21:08:20
--
PacketHandler.ServerErrorHandler = function (packet_data)
	local server_id = packet_data.error_id
	
end

PacketHandler[RSC.SERVER_ERROR_CODE] = PacketHandler.ServerErrorHandler