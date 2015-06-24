--
-- Author: Yangcao
-- Date: 2015-06-23 20:54:59
--

local Log = class("Log")

function Log:ctor(name)
	local doc_dir = cc.FileUtils:getInstance():getWritablePath()
	local abs_dir = doc_dir .. name
	self.fp_ = io.open(abs_dir, "w")
end

function Log:Print(format, ...)

	local msg = string.format(format, ...)
	local date = os.date("%Y-%m-%d %H:%M:%S")
	local out_string = date .. " " .. msg

	if DEBUG == 1 then
		print(msg)
	end

	if self.fp_ then
		self:fp_:write(out_string)
	end
end

return Log