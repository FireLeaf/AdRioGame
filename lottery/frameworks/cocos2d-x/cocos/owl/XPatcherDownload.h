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
		STATUS_RUNNING,//������
		STATUS_FINISH,//���
		STATUS_BLOCK,//����
		STASTUS_DISCONNECT,//����
	};
	struct HttpTask 
	{
		FILE* fp;//�ļ�ָ��
		xint64 begin;//��ʼ��
		xint64 end;//������
		xint64 total;
		xint64 cur;//��ǰָ��
		CURL* http_handle;
		CURLM* multi_handle;
		int status;//��ǰ״̬
		int seconds;//����ʱ��
		int running_handles;
		XHttpDownload* hd;
		HttpTask(){memset(this, 0, sizeof(HttpTask));}
	};
public:
	XHttpDownload(const char* url, const char* local_path, int thread_num);
	~XHttpDownload();
	bool Run(pfnDownloadProgress cb = nullptr, void* data = nullptr);
protected:
	bool InitDownload();//��ʼ������
	void UpdateDownload();//��������
	bool EndDownload();
	void Release();
public:
	xint64 cur_size;
protected:
	std::vector<HttpTask*> http_tasks;//��������
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
	//��ȡ�ļ���С
	static bool GetFileSize(const char* url, xint64& file_size, int& response_code);

	bool DownloadFile(const char* url, const char* local_path, int thread_num, pfnDownloadProgress cb = nullptr, void* data = nullptr);
	bool DownloadFileBackgroud(const char* url, const char* local_path, int thread_num, pfnDownloadProgress cb = nullptr, void* data = nullptr);//�첽����
protected:
	bool HttpRequestFile(const char* url);
private:
	XThread* thread_handle;
};

#endif // XPatcherDownload