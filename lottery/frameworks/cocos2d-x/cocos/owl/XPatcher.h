/**************************************************************************
/*		FileName: XPatcher.h
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2014/11/27 22:49:24
/*		CopyRight: yc 
/*************************************************************************/

#ifndef __XPATCHER__H
#define __XPATCHER__H

#include "XSys.h"
#include <string>
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;
using namespace XSys;

enum PATCHER_EVENT
{
	PE_DNS_RESLOVE,//DNS解析
	PE_DOWNLOAD_PATCHER_CONFIG,//下载最新服务器上的patcher配置
	PE_UPDATE_TO_NEXT_VERSION,//更新到下一版本的资源
	PE_UPDATE_COMPLETE,//更新完成
};

enum PATCHER_STATE
{
	STATE_DNS_RESOLVE,
	STATE_WAIT_PATCHER_CONFIG,
	STATE_UPDATE_ASSET,
	STATE_COMBINE_ASSET,//下载完毕整合资源
	STATE_COMPLETE,
};

enum HttpDownloadErrorReason
{
	HDErrorNone = 0,
	HDErrorTimeout = 1,
	HDErrorInterrupt = 2,
	HDErrorInternal = 3,
};

struct DownloadFileBlock 
{
	std::string url;
	std::string dest;
	int length;
	int use_seconds;
};

struct UploadFileBlock 
{
	std::string url;
	std::string src;
	int length;
	int use_seconds;
};

class X_DLL DownloadWatcher//下载监听者
{
public:
	virtual void OnDownloadBegin(int ) = 0;//开始下载
	virtual void OnDownloadChange(int total_size, int cur_size, int real_speed) = 0;//
	virtual void OnDownloadEnd() = 0;//
	virtual void OnDownloadFinish() = 0;
};

typedef void (*pfnDownloadCallback)(DownloadFileBlock dfb);
typedef void (*pfnUploadCallback)(UploadFileBlock ufb);

enum 
{
	PS_UNKONW,
	PS_NDS_ERROR,// dns reslove failed
	PS_LOCAL_ASSET_BROKEN,
	PS_ASSET_BROKEN,// asset broke
	PS_NETWORK_EXCEPTION,
	PS_APPVER_ERROR,// application error
	PS_CHECK_NETOWRK,
	PS_CHECK_VERSION,
	PS_DOWNLOAD_PATCH,
	PS_APPLY_PATCH,
	PS_FINISH,
};

struct AssetVersion 
{
	int main_version;
	int sub_version;
	int asset_version;
	AssetVersion():main_version(0), sub_version(0), asset_version(0){}
};

struct PatcherEvent
{
	int event_type;
	int parm1;
	int parm2;
	int parm3;
};

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
	PatcherState() : cur_version(), target_version()
	{
		state = PS_UNKONW;
		is_complete = false;
		total_length = 0;
		getted_length = 0;
		cur_index = 0;
		total_length = 0;
		real_speed = 0.0f;
		apply_index = 0;
		total_apply = 0;
	}
};

class X_DLL XPatcher
{
public:
	XPatcher();
	~XPatcher();

	static XPatcher& GetInstance();
	bool Init(const char* writable_path, const char* bundle_path);

	void TrigEvent(const PatcherEvent& pe){}

	void StartPatch(const char* patch_url);//传入更新服务器地址
	PatcherState QueryPatcherState();

	void DownloadFile(const char* url, const char* dest_file){}
	void DownloadFile(const char* url, const char* dest_file, pfnDownloadCallback func){}
	void UploadFile(const char* src_file, const char* url, pfnUploadCallback func){}
	
	void PatchProc();
	void DownloadPathCallBack(void* data, int downloaded, int total, int speed);
	void ApplyPatchCallBack(int cur_apply, int total_apply);
	void Clean();
protected:
	bool LoadLocalAssetVersion(const std::string& asset_update_path, const std::string& bundle_path);
	bool DownloadServerAssetVersion(const std::string& tmp_path);
	bool DowloadPathAndApplay(const std::string& asset_update_path, const std::string& tmp_path);
protected:
	PatcherState patch_state;
	XMutex* status_mutex;
	XThread* patch_thread;
	std::string patch_url;
};

#endif // XPatcher