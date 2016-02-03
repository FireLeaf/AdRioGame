/**************************************************************************
/*		FileName: XFileGroup.cpp
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2015/07/20 20:08:03
/*		CopyRight: yc 
/*************************************************************************/
#include "XFileGroup.h"

XFilePackManage XFileGroup::update_fpm_;
XFilePackManage XFileGroup::bundle_fpm_;

unsigned char* XFileGroup::getFileData(XFilePackManage& pack_man, const std::string& filename, const char* mode, int *size)
{
	std::string pathrecord;
	const char* pack = XFilePackManage::FindPackByFilePath(filename.c_str(), pathrecord);
	if (pack)
	{
		XFilePackageEasy* pack_easy = pack_man.Get().FindPack(pack);
		if (pack_easy)
		{
			XFilePackageEasy::XEasyPackageRecord* record = pack_easy->FindRecord(pathrecord.c_str());
			if (record)
			{
				void* buffer = nullptr;
				pack_easy->ReadFileContent(record, &buffer, (int*)size);
				if (std::string::npos == std::string(mode).find_first_of('b'))
				{
					return (unsigned char*)buffer;
				}
				else
				{
					std::string text_buffer = (char*)buffer;

				}
			}
		}
	}
	return nullptr;
}

unsigned char* XFileGroup::getFileData(const std::string& filename, const char* mode, int *size)
{
	unsigned char* buffer = getFileData(GetUpdatePackMan(), filename, mode, size);
	if (buffer)
	{
		return buffer;
	}

	return getFileData(GetBundlePackMan(), filename, mode, size);
}