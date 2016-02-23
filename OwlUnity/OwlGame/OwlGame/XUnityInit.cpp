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

bool XInit::Init(const char* szWriteablePath, const char* szBundlePath)
{
	const char l_FpkName[][MAX_PACKNAME_PATH] = {"src", "res",};
	XFilePackManage::SetPackNames(l_FpkName, sizeof(l_FpkName) / sizeof(l_FpkName[0]));

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
	XLog::Get().LogOutput(true, "debug", "XPatcher::Init success![bundle path: %s, update path:%s]", szWriteablePath, szBundlePath);

	// init package
	XFilePackManage& bundlePckMan = XFileGroup::GetBundlePackMan();
	if (!bundlePckMan.InitPackMan(XPathMon::GetInstance().GetBundlePath().c_str()))
	{
		XLog::Get().LogOutput(true, "debug", "init bundle package man failed!");
		return false;
	}

	XFilePackManage& updatePckMan = XFileGroup::GetUpdatePackMan();
	if (!updatePckMan.InitPackMan(XPathMon::GetInstance().GetAssetUpdatePath().c_str()))
	{
		XLog::Get().LogOutput(true, "debug", "init update package man failed!");
		return false;
	}

	return true;
}
