--
-- Author: OwlGame
-- Date: 2015-11-18 22:17:45
--
PathUtil = {}

function PathUtil:initSearchPath()
	--打包目录,可读不可写
	self.bundle_path_ = XPathMon:GetInstance():GetBundlePath()
	--打包目录下的init_asset，同上
	self.init_asset_path_ = XPathMon:GetInstance():GetInitAssetPath()
	--可写目录是指doc目录
	self.writeable_path_ = XPathMon:GetInstance():GetWritablePath()
	--指可写目录下的AssetUpdate目录
	self.asset_update_path_ = XPathMon:GetInstance():GetAssetUpdatePath()
	--指可写目录下的Tmp目录
	self.tmp_path_ = XPathMon:GetInstance():GetTmpPath()
	--指可写目录下的GameData目录
	self.game_data_path_ = XPathMon:GetInstance():GetGameDataPath()
	----指可写目录下的log目录
	self.log_path_ = XPathMon:GetInstance():GetLogPath()

	print("bundle_path:" .. self.bundle_path_)
	print("init_asset_path:" .. self.init_asset_path_)
	print("writeable_path:" .. self.writeable_path_)
	print("asset_update_path:" .. self.asset_update_path_)
	print("tmp_path:" .. self.tmp_path_)
	print("game_data_path:" .. self.game_data_path_)
	print("log_path:" .. self.log_path_)

	--优先读取更新目录下的资源
	--添加更新目录下的资源
	cc.FileUtils:getInstance():addSearchPath(self.asset_update_path_ .. "res/")
	--UI file
	cc.FileUtils:getInstance():addSearchPath(self.asset_update_path_ .. "res/UI/")
	cc.FileUtils:getInstance():addSearchPath(self.asset_update_path_ .. "res/UI/Game/")
	--texture
	cc.FileUtils:getInstance():addSearchPath(self.asset_update_path_ .. "res/Texture/")
	cc.FileUtils:getInstance():addSearchPath(self.asset_update_path_ .. "res/Texture/Game/")
	--sound
	cc.FileUtils:getInstance():addSearchPath(self.asset_update_path_ .. "res/Sound/")

	--添加初始化资源的路径
	cc.FileUtils:getInstance():addSearchPath(self.init_asset_path_ .. "res/")
	--UI file
	cc.FileUtils:getInstance():addSearchPath(self.init_asset_path_ .. "res/UI/")
	cc.FileUtils:getInstance():addSearchPath(self.init_asset_path_ .. "res/UI/Game/")
	--texture
	cc.FileUtils:getInstance():addSearchPath(self.init_asset_path_ .. "res/Texture/")
	cc.FileUtils:getInstance():addSearchPath(self.init_asset_path_ .. "res/Texture/Game/")
	--sound
	cc.FileUtils:getInstance():addSearchPath(self.init_asset_path_ .. "res/Sound/")
end

PathUtil:initSearchPath()