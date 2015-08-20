--
-- Author: Yangcao
-- Date: 2015-08-20 22:27:59
--
StringTable = {}
StringTable.GetString = function (key)
	return StringTable[key] or "<"..key..">"
end
import("app.i18n.UpdateString")