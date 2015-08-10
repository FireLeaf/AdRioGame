/**************************************************************************
/*		FileName: XWinSys.cpp
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2014/10/14 20:30:22
/*		CopyRight: yc 
/*************************************************************************/

#include "XSys.h"
#include<thread>
#include <mutex>
#include<stdio.h>
#include "cocos2d.h"
#ifdef _WIN32
#include<io.h>
#else
#include<unistd.h>
#endif

using namespace std;
using namespace cocos2d;
//using namespace cocos2d::extension;

class XC11Mutex : public XMutex
{
public:
	XC11Mutex():mtx(){}
	virtual void Lock(){mtx.lock();}
	virtual bool TryLook(){return mtx.try_lock();}
	virtual void Unlock(){mtx.unlock();}
protected:
	std::mutex mtx;
};

namespace XSys
{
	XThreadPool* XCreateThreadPool(int thread_count){return NULL;}
	void XReleaseThreadPool(XThreadPool*){}
	bool XDeleteFile(const char* path){return true;}
	bool XDeleteDirectory(const char* path, bool bIsSubDelAll){return true;}

	void XLogOutput(const char* log)
	{
		CCLog(log);
	}

	XMutex* XCreateMutex()
	{
		return (new XC11Mutex());
	}

	bool XCreateFile(const char* file_path)
	{
		FILE* fp = fopen(file_path, "wb");
		if(fp)
		{
			fclose(fp);
			return true;
		}
		return false;
	}
	
	bool XCreateDirectory(const char* path)
	{
		//return (TRUE == CreateDirectoryA(path, NULL));
		return FileUtils::getInstance()->createDirectory(path);
	}

	bool XIsFileExist(const char* file_path)
	{
        return FileUtils::getInstance()->isFileExist(file_path);//( (_access( file_path , 0 )) != -1 );
	}

	bool XIsDirectory(const char* path)
	{
		return false;
	}

	bool XSetFileSize(FILE* fp, long size)
	{
#ifdef _WIN32
        bool bRet = (0 == _chsize(XFileNo(fp), size));
#else
        bool bRet = (0 == ftruncate(XFileNo(fp), size));
#endif // _WIN32
        return bRet;
	}

	bool XSetFileSize(const char* path, long size)
	{
		if (!XIsFileExist(path))
		{
			return false;
		}
        
		FILE* fp = fopen(path, "wb");
		if (!fp)
		{
			return false;
		}
       bool bRet = XSetFileSize(fp, size);

		
		fclose(fp);
		return bRet;
	}

	int XFileNo(FILE* fp)
	{
#ifdef _WIN32
		return _fileno(fp);
#else
        return fileno(fp);
#endif
	}
}