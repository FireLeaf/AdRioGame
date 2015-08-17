/*******************************************************************************
	FILE:		XFilePackManager.cpp
	
	DESCRIPTTION:	
	
	CREATED BY: YangCao, 2015/01/16

	Copyright (C) - All Rights Reserved with Coconat
*******************************************************************************/

#include "XFilePackManager.h"
#include "XLog.h"
#include "XSys.h"

const char* g_FpkName[64] = {"src", "res",};

XFilePackManage::XFilePackManage()
{

}

XFilePackManage& XFilePackManage::Get()
{
	static XFilePackManage inst;
	return inst;
}

XFilePackageEasy* XFilePackManage::FindPack(const char* pack_name)
{
	if (!pack_name)
	{
		return NULL;
	}

	for (int i = 0; i < file_pack_items.size(); i++)
	{
		if (0 == strcmp(pack_name, file_pack_items[i]->pack_name.c_str()))
		{
			return file_pack_items[i]->file_pack_easy;
		}
	}
	return NULL;
}

const char* XFilePackManage::FindPackByFilePath(const char* path, std::string& pathrecord)
{
	std::string str_path = path;
	size_t find_pos = str_path.find_first_of('/');
	if (find_pos != std::string::npos)
	{
		std::string predir = str_path.substr(0, find_pos);
		for (int i = 0; i < FPK_COUNT; i++)
		{
			if (strcmp(predir.c_str(), g_FpkName[i]) == 0)
			{
				//pathrecord = "/";
				pathrecord += str_path[find_pos];
				return g_FpkName[i];
			}
		}
	}
	return NULL;
}

bool XFilePackManage::SaveAll()
{
	for (int i = 0; i < file_pack_items.size(); i++)
	{
		FilePackItem* pPackItem = file_pack_items[i];
		if (pPackItem && pPackItem->file_pack_easy)
		{
			pPackItem->file_pack_easy->SavePackageRecords();
			pPackItem->file_pack_easy->Flush();
		}
	}
	return true;
}

bool XFilePackManage::InitPackMan(const char* asset_path)
{
	for (int i = 0; i < FPK_COUNT; i++)
	{
		std::string pck_path = std::string(asset_path) + g_FpkName[i];
		pck_path += ".fpk";
		if (!XSys::XIsFileExist(pck_path.c_str()))
		{
			XFilePackageEasy fpe;
			if (!fpe.CreatePackage(pck_path.c_str()))
			{
				XLog::Get().LogOutput(true, "debug", "CreatePackage %s.fpk failed in directory %s!", g_FpkName, asset_path);
				return false;
			}
			fpe.SavePackageRecords();
			fpe.CloseFile();
		}

		if( !AddPack(g_FpkName[i], asset_path))
		{
			XLog::Get().LogOutput(true, "debug", "AddPack %s to package failed! directory is asset_path");
			return false;
		}
	}
	return true;
}

bool XFilePackManage::AddPack(const char* pack_name, const char* pack_dir)
{
	std::string strpackname = std::string(pack_name) + ".fpk";
	std::string strpackpath = std::string(pack_dir) + strpackname;
	XFilePackageEasy* new_fpe = new XFilePackageEasy;
	if (new_fpe->InitPackage(strpackpath.c_str()))
	{
		FilePackItem* item = new FilePackItem;
		item->pack_name = pack_name;
		item->file_pack_easy = new_fpe;
		file_pack_items.push_back(item);
		return true;
	}
	else
	{
		delete new_fpe;
		return false;
	}
	return false;
}

bool XFilePackManage::AddFile(const char* pack_name, const char* file_path, const void* buffer, int length)
{
	XFilePackageEasy* fpe = FindPack(pack_name);
	if (!fpe)
	{
		return false;
	}

	return fpe->AppendFileFromData(file_path, (const unsigned char*)buffer, length);
}

bool XFilePackManage::DelFile(const char* pack_name, const char* file_path)
{
	XFilePackageEasy* fpe = FindPack(pack_name);
	if (!fpe)
	{
		return false;
	}

	return fpe->RemoveFile(file_path);
}

bool XFilePackManage::ModFile(const char* pack_name, const char* file_path, const void* buffer, int length)
{
	XFilePackageEasy* fpe = FindPack(pack_name);
	if (!fpe)
	{
		return false;
	}

	return fpe->RewriteFileFromData(file_path, (const unsigned char*)buffer, length);
}