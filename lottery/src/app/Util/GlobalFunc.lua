--
-- Author: Yangcao
-- Date: 2015-08-21 22:52:56
--
GlobalFunc = {}

GlobalFunc.ReplaceScene = function (sceneName, args, transitionType, time, more)
	local scenePackageName = "app.scenes." .. sceneName
    local sceneClass = require(scenePackageName)
    local scene = sceneClass.new(unpack(checktable(args)))
    display.replaceScene(scene, transitionType, time, more)
end