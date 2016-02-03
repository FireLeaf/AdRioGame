/**************************************************************************
/*		FileName: XPathMonitor.cpp
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2015/08/05 21:39:03
/*		CopyRight: yc 
/*************************************************************************/

#include "XPathMonitor.h"
#include "XSys.h"
#include "XLog.h"

XPathMon& XPathMon::GetInstance()
{
	static XPathMon inst;
	return inst;
}

bool XPathMon::Init(const char* writable_path, const char* bundle_path)
{
	this->writable_path = writable_path;
	AddPath("writable", this->writable_path.c_str());

	this->bundle_path = bundle_path;
	AddPath("bundle", this->bundle_path.c_str());

	this->init_asset_path = this->bundle_path + "init_asset/";
	AddPath("init_asset", init_asset_path.c_str());

	asset_update_path = this->writable_path + "AssetUpdate/";
	AddPath("asset_update", asset_update_path.c_str());

	tmp_path = this->writable_path + "Tmp/";
	AddPath("tmp", tmp_path.c_str());

	game_data_path = this->writable_path + "GameData/";
	AddPath("game_data", game_data_path.c_str());

	log_path = this->writable_path + "Log/";
	AddPath("log", log_path.c_str());
	return true;
}

bool XPathMon::AddPath(const char* tag, const char* full_path)
{
	if (!tag || !full_path)
	{
		return false;
	}

	if( XSys::XCreateDirectory(full_path) )
	{
		std::string str_tag = tag;
		std::string str_full_path = full_path;
		tag_map_path[str_tag] = str_full_path;
		return true;
	}
	return false;
}

std::string XPathMon::GetPathByTag(const char* tag) const
{
	PathCacheMap::const_iterator iter = tag_map_path.find(tag);
	if (iter != tag_map_path.end())
	{
		return iter->second;
	}
	return std::string("");
}