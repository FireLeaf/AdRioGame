/**************************************************************************
/*		FileName: Platform.cpp
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2015/07/30 19:48:39
/*		CopyRight: yc 
/*************************************************************************/

#ifndef __PLATFORMIOS_US__H
#define __PLATFORMIOS_US__H

#include "Platform.h"

class OGPlatformIOSUS : public OGPlatform
{
public:
	OGPlatformIOSUS(){m_iPlatform = PLATFORM_US_IOS;}
public:
	virtual void Login(const char* szCommand);
	virtual void Logout(const char* szCommand);
};

#endif // PlatformIOS_US
