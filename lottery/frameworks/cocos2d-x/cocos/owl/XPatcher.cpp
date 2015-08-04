/*******************************************************************************
	FILE:		XPatcher.cpp
	
	DESCRIPTTION:	
	
	CREATED BY: YangCao, 2015/08/04

	Copyright (C) - All Rights Reserved with Coconat
*******************************************************************************/

#include "XPatcher.h"

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

XPatcher& XPatcher::GetInstance()
{
	static XPatcher inst;
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

	patch_thread = XCreateThread();
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