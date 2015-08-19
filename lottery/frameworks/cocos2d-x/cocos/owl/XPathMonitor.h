/**************************************************************************
/*		FileName: XPathMonitor.h
/*		FileDesc: manager path
/*		FileAuthor: YangCao
/*		CreateTime: 2015/08/05 21:22:26
/*		CopyRight: yc 
/*************************************************************************/

#ifndef __XPATHMONITOR__H
#define __XPATHMONITOR__H

#include <string>
#include <map>
#include "XPreDefine.h"

class X_DLL XPathMon
{
public:
	typedef std::map<std::string, std::string> PathCacheMap;

	static XPathMon& GetInstance();
public:
	bool Init(const char* writable_path, const char* bundle_path);
	bool AddPath(const char* tag, const char* full_path);
	//bool AddPathToPath(const char* tag, const char* sub_tag, const char* sub_path);
	//bool AddPathToWritablePath(const char* tag, const char* sub_path){return AddPathToPath("writeable", sub_path);}
	//bool AddPathToAssetUpdatePath()
	
	std::string GetPathByTag(const char* tag) const;
	std::string GetWritablePath() const {return writable_path;}
	std::string GetBundlePath() const {return bundle_path;}
	std::string GetInitAssetPath() const {return init_asset_path;}
	std::string GetAssetUpdatePath() const {return asset_update_path;}
	std::string GetTmpPath() const {return tmp_path;}
	std::string GetGameDataPath() const {return game_data_path;}
	std::string GetLogPath() const {return log_path;}
protected:
	std::string writable_path;
	std::string bundle_path;
	std::string init_asset_path;
	std::string asset_update_path;
	std::string tmp_path;
	std::string game_data_path;
	std::string log_path;

	PathCacheMap tag_map_path;
};

#endif // XPathMonitor
