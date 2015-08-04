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
#include <io.h>
#include<stdio.h>
#include "cocos2d.h"

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
		HANDLE hFile = CreateFileA(file_path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL , NULL);
		if ( INVALID_HANDLE_VALUE != hFile)
		{
			CloseHandle(hFile);
		}
		FILE* fp = fopen(file_path, "rb");
		if(!fp)
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
		return ( (_access( file_path , 0 )) != -1 );
	}

	bool XIsDirectory(const char* path)
	{
		return false;
	}

	bool XSetFileSize(FILE* fp, long size)
	{
		return (0 == _chsize(XFileNo(fp), size));
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
#ifdef _WIN32
		bool bRet = (0 == _chsize(XFileNo(fp), size));
#else
		bool bRet = (0 == ftruncate(XFileNo(fp), size));
#endif // _WIN32

		
		fclose(fp);
		return bRet;
	}

	int XFileNo(FILE* fp)
	{
		return _fileno(fp);
	}
}