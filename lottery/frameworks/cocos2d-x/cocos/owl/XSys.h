/**************************************************************************
/*		FileName: XSys.h
/*		FileDesc: 
/*		FileAuthor: YangCaoϵͳ
/*		CreateTime: 2014/10/14 20:28:23
/*		CopyRight: yc 
/*************************************************************************/

#ifndef __XSYS__H
#define __XSYS__H

#include "XType.h"
#include <stdio.h>
class X_DLL XMutex
{
public:
	virtual ~XMutex(){}
public:
	virtual void Lock() = 0;
	virtual void Unlock() = 0;
};

class X_DLL XWrapMutex
{
public:
	XWrapMutex(XMutex* mtx) : _mtx(mtx){ if(_mtx) _mtx->Lock(); }
	~XWrapMutex(){ if(_mtx) _mtx->Unlock(); }
protected:
	XMutex* _mtx;
};

class XEvent
{

};

struct XJobDesc 
{

};

typedef xint32 (*pfnJobProc)(XJobDesc* parm);

class XThread;

struct X_DLL XJob
{
	XJobDesc* desc;
	pfnJobProc job_proc;
//	XThread* thread;
	XJob():desc(nullptr), job_proc(nullptr)/*, thread(NULL)*/{}
};

class X_DLL XThread
{
public:
	enum
	{
		LOWER_PRIORITY,
		NORMAL_PRIORITY,
		HIGH_PRIORITY,
		PRIORITY_NUM,
	};
public:
	XThread():job(), job_mutex(nullptr){}
	virtual ~XThread(){}
public:
	virtual void Suppend() = 0;
	virtual void Stop() = 0;
	virtual void Resume() = 0;
	virtual void Run() = 0;
	virtual void Join() = 0;
protected:
	//std::vector<XJob> jobs[PRIORITY_NUM];
	XJob job;
	XMutex* job_mutex;//
};

class X_DLL XThreadPool
{
public:
	enum
	{
		RUN_EVENT,
		PAUSE_EVENT,
		EXIT_EVENT,
		EVENT_NUM,
	};
public:
	virtual ~XThreadPool(){}

	virtual bool CreateThreadPool(int thread_count) = 0;//
	virtual void ReleaseThreadPool() = 0;
	virtual void PauseThreadPool() = 0;
	virtual void ResumeThreadPool() = 0;

	virtual void DoJob(const XJob& job) = 0;
protected:
};
	
namespace XSys
{
	//日志打印调试器或控制台上
	X_DLL void XLogOutput(const char* log);

	X_DLL XMutex* XCreateMutex();
	X_DLL void XDeleteMutex(XMutex*);
	X_DLL XThread* XCreateThread(pfnJobProc func, XJobDesc* desc);
	X_DLL bool XReleaseThread(XThread*);
	X_DLL XThreadPool* XCreateThreadPool(int thread_count);
	X_DLL void XReleaseThreadPool(XThreadPool*);

//文件操作
	X_DLL bool XCreateFile(const char* file_path);
	X_DLL bool XIsFileExist(const char* file_path);
	X_DLL bool XIsDirectory(const char* path);
	X_DLL bool XCreateDirectory(const char* path);
	X_DLL bool XDeleteFile(const char* path);
	X_DLL bool XDeleteDirectory(const char* path, bool bIsSubDelAll);
	X_DLL bool XSetFileSize(const char* path, long size);
	X_DLL bool XSetFileSize(FILE* fp, long size);
	X_DLL int XFileNo(FILE* fp);
};

#endif // XSys