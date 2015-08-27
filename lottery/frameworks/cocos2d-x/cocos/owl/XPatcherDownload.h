/**************************************************************************
/*		FileName: XPatcherDownload.h
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2014/12/01 20:40:05
/*		CopyRight: yc 
/*************************************************************************/

#ifndef __XPATCHERDOWNLOAD__H
#define __XPATCHERDOWNLOAD__H

#include <string>
#include <curl/curl.h>
#include "XType.h"
#include <vector>
#include "XSys.h"

typedef void (*pfnCallBack)(const void* buffer, int length);
typedef void (*pfnDownloadProgress)(void* data, int downloaded, int total, int speed);

enum 
{
	MIN_FILE_SIZE = 2 * 1024 * 1024,
	MAX_THREAD_NUM = 4,
	DOWNLOAD_WRITE_SAFE_SIZE = 2048,
};

struct X_DLL DownloadFileTask : public XJobDesc
{
	std::string url;
	std::string local_path;
	int thread_num;
	pfnDownloadProgress func;
	void* data;

	DownloadFileTask(const char* url, const char* dest, int thread_num, pfnDownloadProgress func, void* data) 
	{
		this->url = url;
		this->local_path = dest;
		this->thread_num = thread_num;
		this->func = func;
		this->data = data;
	}
};

class X_DLL XHttpDownload
{
public:
	enum DOWNLOAD_STATUS
	{
		STATUS_RUNNING,//运行中
		STATUS_FINISH,//完成
		STATUS_BLOCK,//阻塞
		STASTUS_DISCONNECT,//断连
	};
	struct HttpTask 
	{
		FILE* fp;//文件指针
		xint64 begin;//起始点
		xint64 end;//结束点
		xint64 total;
		xint64 cur;//当前指针
		CURL* http_handle;
		CURLM* multi_handle;
		int status;//当前状态
		int seconds;//花费时间
		int running_handles;
		XHttpDownload* hd;
		HttpTask(){memset(this, 0, sizeof(HttpTask));}
	};
public:
	XHttpDownload(const char* url, const char* local_path, int thread_num);
	~XHttpDownload();
	bool Run(pfnDownloadProgress cb = nullptr, void* data = nullptr);
protected:
	bool InitDownload();//初始化下载
	void UpdateDownload();//更新下载
	bool EndDownload();
	void Release();
public:
	xint64 cur_size;
protected:
	std::vector<HttpTask*> http_tasks;//下载任务
	std::string url;
	std::string local_path;
	int thread_num;
	bool running;
	xint64 file_size;
	int failed_count;
	xint64 last_time;
	xint64 delta_download_size;
};

class X_DLL XPatcherDownload
{
public:
	XPatcherDownload();
	~XPatcherDownload();
public:
	//获取文件大小
	static bool GetFileSize(const char* url, xint64& file_size, int& response_code);

	bool DownloadFile(const char* url, const char* local_path, int thread_num, pfnDownloadProgress cb = nullptr, void* data = nullptr);
	bool DownloadFileBackgroud(const char* url, const char* local_path, int thread_num, pfnDownloadProgress cb = nullptr, void* data = nullptr);//异步下载
protected:
	bool HttpRequestFile(const char* url);
private:
	XThread* thread_handle;
};

#endif // XPatcherDownload