/**************************************************************************
/*		FileName: XFileGroup.h
/*		FileDesc: package ¼¯ºÏ
/*		FileAuthor: YangCao
/*		CreateTime: 2015/07/20 20:07:51
/*		CopyRight: yc 
/*************************************************************************/

#ifndef __XFILEGROUP__H
#define __XFILEGROUP__H

#include "XFilePackManager.h"

class X_DLL XFileGroup
{
public:

	static unsigned char* getFileData(const std::string& filename, const char* mode, int *size);

	static XFilePackManage& GetBundlePackMan(){return bundle_fpm_;}
	static XFilePackManage& GetUpdatePackMan(){return update_fpm_;}
protected:
	static unsigned char* getFileData(XFilePackManage& pack_man, const std::string& filename, const char* mode, int *size);
protected:
	static XFilePackManage update_fpm_;
	static XFilePackManage bundle_fpm_;
};

#endif // XFileGroup