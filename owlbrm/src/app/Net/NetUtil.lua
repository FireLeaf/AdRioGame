--
-- Author: Yangcao
-- Date: 2015-06-19 15:40:12
--
function EncodePacket(net_code, net_data)
	local packet = {id = net_code, data = data,}
	local packet_jason = json.encode(packet)
	return packet
end