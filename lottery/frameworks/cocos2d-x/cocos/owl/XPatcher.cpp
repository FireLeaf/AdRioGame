/*******************************************************************************
	FILE:		XPatcher.cpp
	
	DESCRIPTTION:	
	
	CREATED BY: YangCao, 2015/08/04

	Copyright (C) - All Rights Reserved with Coconat
*******************************************************************************/

#include "XPatcher.h"
#include "XLog.h"
#include "XPathMonitor.h"
#include "XPatcherDownload.h"
#include "XUtil.h"
#include "XPatcherFile.h"
#include "XFileGroup.h"

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

bool XPatcher::Init(const char* writable_path, const char* bundle_path)
{
	if (!XPathMon::GetInstance().Init(writable_path, bundle_path))
	{
		return false;
	}
	
	return true;
}

XPatcher& XPatcher::GetInstance()
{
	static XPatcher inst;
	return inst;
}

xint32 _PatchProc(XJobDesc* parm)
{
	XPatcher::GetInstance().PatchProc();
	return 0;
}

bool XPatcher::LoadLocalAssetVersion(const std::string& asset_update_path, const std::string& bundle_path)
{
	//load local asset version
	{
		//check asset update path version
		std::string update_version_path = asset_update_path + "/asset_ver.ver";
		bool is_get_version = false;

		XFile upver_file;
		if (upver_file.OpenFile(update_version_path.c_str(), "rt"))
		{
			XWrapMutex mtx(status_mutex);
			if (3 == fscanf(upver_file.GetFileHandle(), "%d.%d.%d", 
				&patch_state.cur_version.main_version, 
				&patch_state.cur_version.sub_version, 
				&patch_state.cur_version.asset_version) )
			{
				is_get_version = true;
			}
			else
			{
				memset(&patch_state.cur_version, 0, sizeof(patch_state.cur_version));
			}
		}
		upver_file.CloseFile();

		// if no update version then check bundle path version
		if(!is_get_version)
		{
			std::string bundle_version_path = bundle_path + "/InitAsset/asset_ver.ver";
			XFile bdver_file;
			if (bdver_file.OpenFile(bundle_version_path.c_str(), "rt"))
			{
				XWrapMutex mtx(status_mutex);
				// if parser this failed. it may be asset broken
				if (3 != fscanf(upver_file.GetFileHandle(), "%d.%d.%d", 
					&patch_state.cur_version.main_version, 
					&patch_state.cur_version.sub_version, 
					&patch_state.cur_version.asset_version) )
				{
					patch_state.state = PS_ASSET_BROKEN;
					return false;
				}
			}
		}
	}

	return true;
}

bool XPatcher::DownloadServerAssetVersion(const std::string& tmp_path)
{
	std::string tmp_version_path = tmp_path + "asset_ver.ver";
	std::string version_url = patch_url + "asset_ver.ver";
	XPatcherDownload pd;
	if( pd.DownloadFile(version_url.c_str(), tmp_version_path.c_str(), 1) )
	{
		XFile tvver_file;
		if (tvver_file.OpenFile(tmp_version_path.c_str(), "rt"))
		{
			// if parser this failed. it may be asset broken
			if (3 != fscanf(tvver_file.GetFileHandle(), "%d.%d.%d", 
				&patch_state.target_version.main_version, 
				&patch_state.target_version.sub_version, 
				&patch_state.target_version.asset_version) )
			{
				XWrapMutex mtx(status_mutex);
				memset(&patch_state.target_version, 0, sizeof(AssetVersion));
				patch_state.state = PS_NETWORK_EXCEPTION;
				return false;
			}

			if (patch_state.target_version.main_version != patch_state.cur_version.main_version
				|| patch_state.target_version.sub_version != patch_state.cur_version.sub_version
				)
			{
				XWrapMutex mtx(status_mutex);
				patch_state.state = PS_APPVER_ERROR;
				return false;
			}

			return true;
		}
	}
	return false;
}

void _DownloadPathCallBack(void* data, int downloaded, int total, int speed)
{
	if (data)
	{
		((XPatcher*)data)->DownloadPathCallBack(data, downloaded, total, speed);
	}
}

void XPatcher::DownloadPathCallBack(void* data, int downloaded, int total, int speed)
{
	XWrapMutex mtx(status_mutex);
	patch_state.real_speed = speed;
	patch_state.total_length = total;
	patch_state.getted_length = downloaded;
}

bool XPatcher::DowloadPathAndApplay(const std::string& asset_update_path, const std::string& tmp_path)
{
	int main_version = 0;
	int sub_version = 0;
	int cur_asset_version = 0;
	int tar_asset_version = 0;
	{
		XWrapMutex mtx(status_mutex);
		cur_asset_version = patch_state.cur_version.asset_version;
		tar_asset_version = patch_state.target_version.asset_version;
		main_version = patch_state.cur_version.main_version;
		sub_version = patch_state.cur_version.sub_version;
		if ( cur_asset_version >= tar_asset_version )
		{
			patch_state.state = PS_FINISH;
			return true;
		}
	}

	int total_count = tar_asset_version - cur_asset_version;
	for (int i = 0; i < total_count; i++)
	{
		std::string patch_local_path;
		std::string patch_p_url;
		{
			XWrapMutex mtx(status_mutex);
			patch_state.cur_index = 0;
			patch_state.total_count = total_count;
			patch_state.getted_length = 0;
			patch_state.total_length = 1;// prevent div 0
			FormatString(patch_p_url, "%s/patch_%d_%d_%d.p", patch_url, patch_state.cur_version.main_version, patch_state.cur_version.sub_version, patch_state.cur_version.asset_version + 1);
			FormatString(patch_local_path, "%s/patch_%d_%d_%d.p", tmp_path,  patch_state.cur_version.main_version, patch_state.cur_version.sub_version, patch_state.cur_version.asset_version + 1);
		}

		//download patch
		{
			XWrapMutex mtx(status_mutex);
			patch_state.state = PS_DOWNLOAD_PATCH;
			return false;
		}

		XPatcherDownload pd;
		if (!pd.DownloadFile(patch_p_url.c_str(), patch_local_path.c_str(), 1, _DownloadPathCallBack, (void*)this))
		{
			XWrapMutex mtx(status_mutex);
			patch_state.state = PS_NETWORK_EXCEPTION;
			return false;
		}

		//apply patch
		{
			XWrapMutex mtx(status_mutex);
			patch_state.state = PS_APPLY_PATCH;
			return false;
		}
		XPathcherFile pf;
		if (pf.LoadPatch(patch_local_path.c_str()))
		{
			if(!pf.ApplyPatch(XFileGroup::GetUpdatePackMan(), asset_update_path.c_str()))
			{
				//patch breaken
				XWrapMutex mtx(status_mutex);
				patch_state.state = PS_NETWORK_EXCEPTION;
				return false;
			}
		}
		else
		{
			//patch breaken
			XWrapMutex mtx(status_mutex);
			patch_state.state = PS_NETWORK_EXCEPTION;
			return false;
		}
		pf.CloseFile();
		

		{
			XWrapMutex mtx(status_mutex);
			patch_state.cur_version.asset_version++;
			cur_asset_version = patch_state.cur_version.asset_version;
		}

		std::string update_version_path = asset_update_path + "/asset_ver.ver";
		XFile file_ver;
		if (file_ver.OpenFile(update_version_path.c_str(), "wt"))
		{
			fprintf(file_ver.GetFileHandle(), "%d.%d.%d", main_version, sub_version, cur_asset_version);
		}
		else
		{
			//patch breaken
			XWrapMutex mtx(status_mutex);
			patch_state.state = PS_UNKONW;
			return false;
		}
		file_ver.CloseFile();
	}
	return true;
}

void XPatcher::PatchProc()
{
	std::string asset_update_path = XPathMon::GetInstance().GetAssetUpdatePath();
	std::string bundle_path = XPathMon::GetInstance().GetBundlePath();
	std::string tmp_path = XPathMon::GetInstance().GetTmpPath();
	{
		XWrapMutex mtx(status_mutex);
		patch_state.state = PS_CHECK_VERSION;
	}
	// load local asset version
	if (!LoadLocalAssetVersion(asset_update_path, bundle_path))
	{
		return;
	}

	//download server asset version
	if (!DownloadServerAssetVersion(tmp_path))
	{
		return;
	}

	//download and apply patch 
	if (!DowloadPathAndApplay(asset_update_path, tmp_path))
	{
		return;
	}

	{
		XWrapMutex mtx(status_mutex);
		patch_state.state = PS_FINISH;
	}
}

void XPatcher::StartPatch(const char* patch_url)
{
	this->patch_url = patch_url;
	if (!status_mutex)
	{
		XLog::Get().LogOutput(true, "patch", "dddd");
		//...
	}

	patch_thread = XCreateThread(_PatchProc, NULL);
}

PatcherState XPatcher::QueryPatcherState()
{
	PatcherState ps;
	if (status_mutex)
	{
		XWrapMutex wm(status_mutex);
		ps = patch_state;
	}
	return ps;
}