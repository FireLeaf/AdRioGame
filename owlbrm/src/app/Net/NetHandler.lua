--
-- Author: Yangcao
-- Date: 2015-06-19 11:36:31
--

local NetHandler = class("NetHandler")

function NetHandler:ctor()
	
end

function NetHandler:HanderHttp(http_post)
	if http_post then
		return
	end

	local ready_state = http_post.readyState
	local status = http_post.status

	if ready_state == 4 and status == 200 then
		local response = http_post.response
		local packet = json.decode(response, 1)
		self:DistpatchPacket(packet)
	end
end

function NetHandler:DistpatchPacket(packet)
	if nil == packet then
		return
	end
	
	local packet_id = packet.id
	if nil == packet_id or type(packet_id) ~= "number" then
		return
	end

	local handler = PacketHandler[packet_id]
	if handler then
		local packet_data = packet.data
		handler(packet_data)
	end
end