/**************************************************************************
/*		FileName: Platform.cpp
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2015/07/30 19:48:39
/*		CopyRight: yc 
/*************************************************************************/

#include "Platform.h"
#include "PlatformIOS_US.h"


OGPlatform* OGPlatform::GetInstance()
{
#ifdef _PLATFORM_IOS_US_
	return new OGPlatformIOSUS;
#endif
	return NULL;
}