/*******************************************************************************
	FILE:		XFilePackManager.h
	
	DESCRIPTTION:	
	
	CREATED BY: YangCao, 2015/01/16

	Copyright (C) - All Rights Reserved with Coconat
*******************************************************************************/

#ifndef __COCONAT_XFILEPACKMANAGER_H_
#define __COCONAT_XFILEPACKMANAGER_H_

#include "XFilePackage.h"
#include <string>

#define MAX_PACKNAME_PATH 64
class X_DLL XFilePackManage
{
public:
	struct FilePackItem 
	{
		std::string pack_name;//包名
		XFilePackageEasy* file_pack_easy;
	};
public:
	XFilePackManage();
public:
	static XFilePackManage& Get();

	static void SetPackNames(const char name_array[][MAX_PACKNAME_PATH], int count){
		pack_names.clear();
		for (int i = 0; i < count; i++){pack_names.push_back(name_array[i]);}
	}
public:
	bool InitPackMan(const char* asset_path);
	bool AddPack(const char* pack_path, const char* pack_dir);//增加一个包
	//
	bool AddFile(const char* pack_name, const char* file_path, const void* buffer, int length);
	bool DelFile(const char* pack_name, const char* file_path);
	bool ModFile(const char* pack_name, const char* file_path, const void* buffer, int length);
	//bool RepFile(const char* pack_name, const char*);
	XFilePackageEasy* FindPack(const char* pack_name);
	static const char* FindPackByFilePath(const char* path, std::string& pathkey);
	bool SaveAll();
protected:
	std::vector<FilePackItem*> file_pack_items;
	static std::vector<std::string> pack_names;
};

#endif