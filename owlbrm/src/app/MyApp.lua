
require("config")
require("cocos.init")
require("framework.init")

local MyApp = class("MyApp", cc.mvc.AppBase)

function MyApp:ctor()
    MyApp.super.ctor(self)
end

function MyApp:run()
    cc.FileUtils:getInstance():addSearchPath("res/")
    --cc.FileUtils:getInstance():addSearchPath("res/Login/")
    import("app.Init")

    HttpDownload = import("app.Patcher.HttpDownload").new()
    HttpDownload:Download()
    self:enterScene("LoginScene")
end

return MyApp
