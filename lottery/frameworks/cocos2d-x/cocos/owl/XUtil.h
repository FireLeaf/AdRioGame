/**************************************************************************
/*		FileName: XUtil.h
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2015/08/05 23:30:56
/*		CopyRight: yc 
/*************************************************************************/

#ifndef __XUTIL__H
#define __XUTIL__H

#include "XPreDefine.h"
#include <string>

X_DLL std::string& FormatString(std::string& str,const char* format, ...);

#endif // XUtil