--
-- Author: Yangcao
-- Date: 2015-08-20 22:25:48
--

--[[enum 
{
	PS_START,
	PS_CHECK_NETOWRK,
	PS_CHECK_VERSION,
	PS_DOWNLOAD_PATCH,
	PS_APPLY_PATCH,
	PS_FINISH,
	PS_UNKONW,
	PS_NDS_ERROR,// dns reslove failed
	PS_LOCAL_ASSET_BROKEN,
	PS_ASSET_BROKEN,// asset broke
	PS_NETWORK_EXCEPTION,
	PS_APPVER_ERROR,// application error
	PS_PATCH_ERROR,
};]]

StringTable["PATCHER_STARTING"] = "启动更新"
StringTable["PATCHER_CHECK_NETWORK"] = "检查网络状况"
StringTable["PATCHER_CHECK_VERSION"] = "检查资源版本号"
StringTable["PATCHER_DOWNLOAD_PATCH"] = "下载补丁中"
StringTable["PATCHER_APPLAY_PATCH"] = "应用补丁"
StringTable["PATCHER_FINISH"] = "更新完成"
StringTable["PATCHER_UNKONW"] = "未知错误"
StringTable["PATCHER_DNS_ERROR"] = "DNS错误！请检查网络状况!"
StringTable["PATCHER_LOCAL_ASSET_BROKEN"] = "本地资源被损坏"
StringTable["PATCHER_ASSET_BROKEN"] = "资源被损坏"
StringTable["PATCHER_NETWORK_EXCEPTION"] = "网络异常"
StringTable["PATCHER_APPVER_ERROR"] = "请更新最新的程序包"
StringTable["PATCHER_PATCH_ERROR"] = "下载的更新包被损坏"

struct PatcherState 
{
	AssetVersion cur_version; //current version
	AssetVersion target_version;// target version
	int state;//current status
	bool is_complete;// is complete not use
	int total_length;// downloading currrent file total length
	int getted_length;// dowloaded current file currrent length
	int cur_index;// download current file index
	int total_count; // total need download file
	float real_speed;// current download speed
	int apply_index; // current patch apply current index
	int total_apply; // total patch need to be applied
}