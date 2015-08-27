/**************************************************************************
 /*		FileName: LuaUtil.h
 /*		FileDesc:
 /*		FileAuthor: YangCao
 /*		CreateTime: 2015/07/30 19:31:55
 /*		CopyRight: yc
 /*************************************************************************/

#ifndef _OG_LUAUTIL_H_
#define _OG_LUAUTIL_H_

#include <map>
#include <set>
#include <string>

namespace LuaUtil {
    void ExcuteLuaFunction(const char* function);
	class XLuaScript
	{
	public:
		typedef std::map<std::string, int> LoadedScriptMap;
	public:
		static XLuaScript& GetInstance()
		{
			static XLuaScript inst;
			return inst;
		}

		bool ExcuteScript(const char* path, bool is_excute_once = true);
		bool CleanScript();
	protected:
		LoadedScriptMap loaded_script_map;
	};
}

#endif