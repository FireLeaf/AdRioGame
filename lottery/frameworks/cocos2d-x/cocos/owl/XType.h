/**************************************************************************
/*		FileName: XType.h
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2014/07/29 19/45/22
/*		CopyRight: yc 
/*************************************************************************/

#ifndef __XTYPE__H
#define __XTYPE__H

#ifdef _WIN32
typedef char xchar;
typedef unsigned char xbyte;
typedef short xshort;
typedef unsigned short xushort;
typedef int xint32;
typedef unsigned int xuint32;
typedef __int64 xint64;
typedef unsigned __int64 xuint64;
typedef long xlong;
typedef unsigned long xulong;
typedef unsigned char xbool;
#else
typedef char xchar;
typedef unsigned char xbyte;
typedef short xshort;
typedef unsigned short xushort;
typedef int xint32;
typedef unsigned int xuint32;
typedef int64_t xint64;
//typedef unsigned int64_t xuint64;
typedef unsigned long long ULONGLONG;
typedef long xlong;
typedef unsigned long xulong;
typedef unsigned char xbool;
#endif

#endif // XType