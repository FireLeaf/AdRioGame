--
-- Author: Yangcao
-- Date: 2015-06-19 11:36:31
--

local NetHandler = class("NetHandler")

function NetHandler:ctor()
	
end

function NetHandler:HanderHttp(http_post, url, id)
	if not http_post then
		return
	end

	local ready_state = http_post.readyState
	local status = http_post.status

	print(url .. "[id:"..id.."]response msg:" .. http_post.response .. " ready_state:" .. ready_state .. " status:" .. status)
	if ready_state == 4 and status == 200 then
		local response = http_post.response
		local packet = json.decode(response, 1)
		if not packet then
			print("unknow response packet[id=" .. id .. "]")
		end
		self:DistpatchPacket(packet)
	else
		print("network bad!")
	end
end

function NetHandler:DistpatchPacket(packet)
	if not packet then
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

return NetHandler