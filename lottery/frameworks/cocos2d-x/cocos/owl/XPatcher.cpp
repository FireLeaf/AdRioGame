/*******************************************************************************
	FILE:		XPatcher.cpp
	
	DESCRIPTTION:	
	
	CREATED BY: YangCao, 2015/08/04

	Copyright (C) - All Rights Reserved with Coconat
*******************************************************************************/

#include "XPatcher.h"
#include "XLog.h"
extern std::string g_WritablePath;//ios上是document目录
extern std::string g_BundlePath;//资源打包的目录

XPatcher::XPatcher()
{
	status_mutex = XCreateMutex();
	patch_thread = NULL;
}

XPatcher::~XPatcher()
{
	if (status_mutex)
	{
		XDeleteMutex(status_mutex);
	}
}

bool XPatcher::Init()
{
	g_WritablePath = FileUtils::getInstance()->getWritablePath();
	g_BundlePath = FileUtils::getInstance()->getBundlePath();
	SetInited();
	return true;
}

XPatcher& XPatcher::GetInstance()
{
	static XPatcher inst;
	if (!inst.IsInited())
	{
		inst.Init();
	}
	return inst;
}

void XPatcher::StartPatch(const char* patch_url)
{
	this->patch_url = patch_url;
	if (!status_mutex)
	{
		XLog::Get().LogOutput(true, "patch", "dddd");
		//...
	}

	//patch_thread = XCreateThread();
}

PatcherState XPatcher::QueryPatcherState()
{
	PatcherState ps;
	if (status_mutex)
	{
		status_mutex->Lock();
		ps = patch_state;
		status_mutex->Unlock();
	}
	return ps;
}