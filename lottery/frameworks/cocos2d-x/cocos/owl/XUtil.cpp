/**************************************************************************
/*		FileName: XUtil.cpp
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2015/08/05 23:32:22
/*		CopyRight: yc 
/*************************************************************************/

#include "XUtil.h"
#include <stdarg.h>

std::string& FormatString(std::string& str,const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	char buf[1024] = {'\0'};
	vsnprintf(buf, 1023, format, ap);
	va_end(ap);

	str = buf;
	return str;
}