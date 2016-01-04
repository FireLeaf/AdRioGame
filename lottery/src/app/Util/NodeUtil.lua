--
-- Author: Owl
-- Date: 2015-07-06 21:34:35
--

NodeUtil = 
{
	--Set
}

Counter = class("Counter")

function Counter:ctor(total_counter, enable, pause)
	self.enable_ = enable 
	self.cur_counter_ = 0
	self.total_counter_ = 0
	self.pause_ = false
end

function Counter:isEnable()
	return self.enable_
end

function Counter:enable()
	self.enable_ = true
end

function Counter:disable()
	self.enable_ = false
end

function Counter:isPause()
	return self.pause_
end

function Counter:pause()
	self.pause_ = true
end

function Counter:resume()
	self.pause_ = false
end

function Counter:curCounter()
	return self.cur_counter_
end

function Counter:totalCounter()
	return self.total_counter_
end

function Counter:isFull()
	return self.cur_counter_ >= self.total_counter_
end

function Counter:incCounter(dt)
	if self:isEnable() == false or self:isPause() then
		return false
	end
	self.cur_counter_ = self.cur_counter_ + dt
	if self:isFull() then
		self.cur_counter_ = self.total_counter_
		self:pause()
		return true
	end
	return false
end