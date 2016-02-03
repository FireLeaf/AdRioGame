/**************************************************************************
/*		FileName: XUnityExport.cpp
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2016/01/18 0:11:25
/*		CopyRight: yc 
/*************************************************************************/

#include "XInit.h"
#include "XFileGroup.h"

#define __STDCALL_ __stdcall

typedef void (__STDCALL_ *pfnSCDownloadProgress)(void* data, int downloaded, int total, int speed);

struct DownloadCBWrap 
{
	pfnSCDownloadProgress unityCallback;
};

static void UnityDownloadProgress(){

}

extern "C"{

	X_DLL bool __STDCALL_ og_initModule(const char* szWriteablePath, const char* szBundlePath) 
	{
		return XInit::Init(szWriteablePath, szBundlePath);
	}

	X_DLL unsigned char* __STDCALL_ og_getFileData(const char* szFileName, int* fileSize)
	{
		return XFileGroup::getFileData(std::string(szFileName), "", fileSize);
	}

	X_DLL void __STDCALL_ og_releaseBuffer(const void* buf)
	{
		delete buf;
	}
};