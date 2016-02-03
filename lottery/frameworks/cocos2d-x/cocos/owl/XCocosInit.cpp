/**************************************************************************
/*		FileName: XCocosInit.cpp
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2015/08/17 0:21:25
/*		CopyRight: yc 
/*************************************************************************/

#include "XInit.h"
#include "XPatcher.h"
#include "XLog.h"
#include "XFilePackManager.h"
#include "XFileGroup.h"
#include "XPathMonitor.h"
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;
using namespace XSys;

const char l_FpkName[][64] = {"src", "res",};
const char** g_FpkName = (const char**)l_FpkName;

bool XInit::Init(const char* szWriteablePath, const char* szBundlePath)
{
	XFilePackManage::s_pack_count = sizeof(l_FpkName) / sizeof(l_FpkName[0]);

	if (!XPathMon::GetInstance().Init(szWriteablePath, szBundlePath))
	{
		return false;
	}
	// init path
	if (!XPatcher::GetInstance()->Init())
	{
		return false;
	}

	// init log system
	XLog::Get().SetLogDir(XPathMon::GetInstance().GetLogPath().c_str());
	XLog::Get().AddLogItem("debug", "OwlDebug.log");
	XLog::Get().LogOutput(true, "debug", "XPatcher::Init success![bundle path: %s, update path:%s]", FileUtils::getInstance()->getWritablePath().c_str(), FileUtils::getInstance()->getBundlePath().c_str());

	// init package
	XFilePackManage& bundlePckMan = XFileGroup::GetBundlePackMan();
	if (!bundlePckMan.InitPackMan(XPathMon::GetInstance().GetBundlePath().c_str()))
	{
		XLog::Get().LogOutput(true, "debug", "init bundle package man failed!");
		return false;
	}
	for (int i = 0; i < XFilePackManage::s_pack_count; i++)
	{
		FileUtils::getInstance()->addSearchPath(XPathMon::GetInstance().GetBundlePath() + std::string(g_FpkName[i]) + "/");
	}

	XFilePackManage& updatePckMan = XFileGroup::GetUpdatePackMan();
	if (!updatePckMan.InitPackMan(XPathMon::GetInstance().GetAssetUpdatePath().c_str()))
	{
		XLog::Get().LogOutput(true, "debug", "init update package man failed!");
		return false;
	}
	for (int i = 0; i < XFilePackManage::s_pack_count; i++)
	{
		FileUtils::getInstance()->addSearchPath(XPathMon::GetInstance().GetAssetUpdatePath() + std::string(g_FpkName[i]) + "/");
		FileUtils::getInstance()->addSearchPath(XPathMon::GetInstance().GetInitAssetPath() + std::string(g_FpkName[i]) + "/");
	}

	//XPatcher::GetInstance().StartPatch("http://127.0.0.1/patch_us/0.0.1/");
	FileUtils::getInstance()->addSearchPath(XPathMon::GetInstance().GetWritablePath());
	FileUtils::getInstance()->addSearchPath(XPathMon::GetInstance().GetBundlePath());
	FileUtils::getInstance()->addSearchPath(XPathMon::GetInstance().GetInitAssetPath());
	FileUtils::getInstance()->addSearchPath(XPathMon::GetInstance().GetGameDataPath());
	FileUtils::getInstance()->addSearchPath(XPathMon::GetInstance().GetAssetUpdatePath());

	return true;
}