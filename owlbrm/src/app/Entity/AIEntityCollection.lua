--
-- Author: Yangcao
-- Date: 2015-06-16 14:27:25
--
local AIEntityCollection = class("AIEntityCollection")

function AIEntityCollection:ctor()
	self.ai_entities_ = {}
end

function AIEntityCollection:AddEntity(id)
	if self.ai_entities_[id] then
		return self.ai_entities_[id]
	end
	local new_entity = AIEntity.new(id)
	self.ai_entities_[id] = new_entity
	return new_entity
end

function AIEntityCollection:GetEntityByID(id)
	return self.ai_entities_[id]
end

function AIEntityCollection:AddEntityWithDetail(detail_info)
	
end

return AIEntityCollection