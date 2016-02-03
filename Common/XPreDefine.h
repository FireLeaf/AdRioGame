/**************************************************************************
/*		FileName: XPreDefine.h
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2015/08/05 20:29:03
/*		CopyRight: yc 
/*************************************************************************/

#ifndef __XPREDEFINE__H
#define __XPREDEFINE__H

#pragma warning( disable : 4068 4996 4251)

#if defined(CC_STATIC)
	#define X_DLL
#else
	#if defined(_USRDLL)
		#define X_DLL     __declspec(dllexport)
	#else         /* use a DLL library */
		#define X_DLL     __declspec(dllimport)
	#endif
#endif

#ifdef _WIN32
#ifndef snprintf
#define snprintf _snprintf
#endif
#endif

#endif // XPreDefine



