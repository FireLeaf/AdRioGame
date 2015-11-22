/*
** Lua binding: owl
** Generated automatically by tolua++-1.0.92 on 11/18/15 23:47:21.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_owl_open (lua_State* tolua_S);

#include "owl/XFileGroup.h"
#include "owl/XFilePackManager.h"
#include "owl/XLog.h"
#include "owl/XSys.h"
#include "owl/XPatcher.h"
#include "owl/XPathMonitor.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_XThreadPool (lua_State* tolua_S)
{
 XThreadPool* self = (XThreadPool*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_xint32 (lua_State* tolua_S)
{
 xint32* self = (xint32*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_XJob (lua_State* tolua_S)
{
 XJob* self = (XJob*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_PatcherState (lua_State* tolua_S)
{
 PatcherState* self = (PatcherState*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_XPatcher (lua_State* tolua_S)
{
 XPatcher* self = (XPatcher*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_XMutex (lua_State* tolua_S)
{
 XMutex* self = (XMutex*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_XLog (lua_State* tolua_S)
{
 XLog* self = (XLog*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_XFilePackManage (lua_State* tolua_S)
{
 XFilePackManage* self = (XFilePackManage*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_XThread (lua_State* tolua_S)
{
 XThread* self = (XThread*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"XFile");
 tolua_usertype(tolua_S,"XThreadPool");
 tolua_usertype(tolua_S,"PatcherEvent");
 tolua_usertype(tolua_S,"XPathMon");
 tolua_usertype(tolua_S,"XPatcher");
 tolua_usertype(tolua_S,"XLog");
 tolua_usertype(tolua_S,"pfnUploadCallback");
 tolua_usertype(tolua_S,"XFilePackManage::FilePackItem");
 tolua_usertype(tolua_S,"pfnDownloadCallback");
 tolua_usertype(tolua_S,"PatcherState");
 tolua_usertype(tolua_S,"XFileGroup");
 tolua_usertype(tolua_S,"XMutex");
 tolua_usertype(tolua_S,"FILE");
 tolua_usertype(tolua_S,"pfnJobProc");
 tolua_usertype(tolua_S,"xint32");
 tolua_usertype(tolua_S,"XFilePackageEasy");
 tolua_usertype(tolua_S,"XEvent");
 tolua_usertype(tolua_S,"XJob");
 tolua_usertype(tolua_S,"XLog::LogItem");
 tolua_usertype(tolua_S,"XJobDesc");
 tolua_usertype(tolua_S,"AssetVersion");
 tolua_usertype(tolua_S,"XFilePackManage");
 tolua_usertype(tolua_S,"XThread");
}

/* method: getFileData of class  XFileGroup */
#ifndef TOLUA_DISABLE_tolua_owl_XFileGroup_getFileData00
static int tolua_owl_XFileGroup_getFileData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XFileGroup",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const char* mode = ((const char*)  tolua_tostring(tolua_S,3,0));
  int size = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   unsigned char* tolua_ret = (unsigned char*)  XFileGroup::getFileData(filename,mode,&size);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filename);
   tolua_pushnumber(tolua_S,(lua_Number)size);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFileData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBundlePackMan of class  XFileGroup */
#ifndef TOLUA_DISABLE_tolua_owl_XFileGroup_GetBundlePackMan00
static int tolua_owl_XFileGroup_GetBundlePackMan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XFileGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XFilePackManage& tolua_ret = (XFilePackManage&)  XFileGroup::GetBundlePackMan();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"XFilePackManage");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBundlePackMan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUpdatePackMan of class  XFileGroup */
#ifndef TOLUA_DISABLE_tolua_owl_XFileGroup_GetUpdatePackMan00
static int tolua_owl_XFileGroup_GetUpdatePackMan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XFileGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XFilePackManage& tolua_ret = (XFilePackManage&)  XFileGroup::GetUpdatePackMan();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"XFilePackManage");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUpdatePackMan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pack_name of class  FilePackItem */
#ifndef TOLUA_DISABLE_tolua_get_XFilePackManage__FilePackItem_pack_name
static int tolua_get_XFilePackManage__FilePackItem_pack_name(lua_State* tolua_S)
{
  XFilePackManage::FilePackItem* self = (XFilePackManage::FilePackItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pack_name'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->pack_name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pack_name of class  FilePackItem */
#ifndef TOLUA_DISABLE_tolua_set_XFilePackManage__FilePackItem_pack_name
static int tolua_set_XFilePackManage__FilePackItem_pack_name(lua_State* tolua_S)
{
  XFilePackManage::FilePackItem* self = (XFilePackManage::FilePackItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pack_name'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pack_name = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: file_pack_easy of class  FilePackItem */
#ifndef TOLUA_DISABLE_tolua_get_XFilePackManage__FilePackItem_file_pack_easy_ptr
static int tolua_get_XFilePackManage__FilePackItem_file_pack_easy_ptr(lua_State* tolua_S)
{
  XFilePackManage::FilePackItem* self = (XFilePackManage::FilePackItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'file_pack_easy'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->file_pack_easy,"XFilePackageEasy");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: file_pack_easy of class  FilePackItem */
#ifndef TOLUA_DISABLE_tolua_set_XFilePackManage__FilePackItem_file_pack_easy_ptr
static int tolua_set_XFilePackManage__FilePackItem_file_pack_easy_ptr(lua_State* tolua_S)
{
  XFilePackManage::FilePackItem* self = (XFilePackManage::FilePackItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'file_pack_easy'",NULL);
  if (!tolua_isusertype(tolua_S,2,"XFilePackageEasy",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->file_pack_easy = ((XFilePackageEasy*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  XFilePackManage */
#ifndef TOLUA_DISABLE_tolua_owl_XFilePackManage_new00
static int tolua_owl_XFilePackManage_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XFilePackManage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XFilePackManage* tolua_ret = (XFilePackManage*)  Mtolua_new((XFilePackManage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XFilePackManage");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  XFilePackManage */
#ifndef TOLUA_DISABLE_tolua_owl_XFilePackManage_new00_local
static int tolua_owl_XFilePackManage_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XFilePackManage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XFilePackManage* tolua_ret = (XFilePackManage*)  Mtolua_new((XFilePackManage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XFilePackManage");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get of class  XFilePackManage */
#ifndef TOLUA_DISABLE_tolua_owl_XFilePackManage_Get00
static int tolua_owl_XFilePackManage_Get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XFilePackManage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XFilePackManage& tolua_ret = (XFilePackManage&)  XFilePackManage::Get();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"XFilePackManage");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InitPackMan of class  XFilePackManage */
#ifndef TOLUA_DISABLE_tolua_owl_XFilePackManage_InitPackMan00
static int tolua_owl_XFilePackManage_InitPackMan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XFilePackManage",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XFilePackManage* self = (XFilePackManage*)  tolua_tousertype(tolua_S,1,0);
  const char* asset_path = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InitPackMan'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->InitPackMan(asset_path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InitPackMan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddPack of class  XFilePackManage */
#ifndef TOLUA_DISABLE_tolua_owl_XFilePackManage_AddPack00
static int tolua_owl_XFilePackManage_AddPack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XFilePackManage",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XFilePackManage* self = (XFilePackManage*)  tolua_tousertype(tolua_S,1,0);
  const char* pack_path = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* pack_dir = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPack'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddPack(pack_path,pack_dir);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddPack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddFile of class  XFilePackManage */
#ifndef TOLUA_DISABLE_tolua_owl_XFilePackManage_AddFile00
static int tolua_owl_XFilePackManage_AddFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XFilePackManage",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XFilePackManage* self = (XFilePackManage*)  tolua_tousertype(tolua_S,1,0);
  const char* pack_name = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* file_path = ((const char*)  tolua_tostring(tolua_S,3,0));
  const void* buffer = ((const void*)  tolua_touserdata(tolua_S,4,0));
  int length = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddFile(pack_name,file_path,buffer,length);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DelFile of class  XFilePackManage */
#ifndef TOLUA_DISABLE_tolua_owl_XFilePackManage_DelFile00
static int tolua_owl_XFilePackManage_DelFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XFilePackManage",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XFilePackManage* self = (XFilePackManage*)  tolua_tousertype(tolua_S,1,0);
  const char* pack_name = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* file_path = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DelFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->DelFile(pack_name,file_path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DelFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ModFile of class  XFilePackManage */
#ifndef TOLUA_DISABLE_tolua_owl_XFilePackManage_ModFile00
static int tolua_owl_XFilePackManage_ModFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XFilePackManage",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XFilePackManage* self = (XFilePackManage*)  tolua_tousertype(tolua_S,1,0);
  const char* pack_name = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* file_path = ((const char*)  tolua_tostring(tolua_S,3,0));
  const void* buffer = ((const void*)  tolua_touserdata(tolua_S,4,0));
  int length = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ModFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->ModFile(pack_name,file_path,buffer,length);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ModFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindPack of class  XFilePackManage */
#ifndef TOLUA_DISABLE_tolua_owl_XFilePackManage_FindPack00
static int tolua_owl_XFilePackManage_FindPack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XFilePackManage",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XFilePackManage* self = (XFilePackManage*)  tolua_tousertype(tolua_S,1,0);
  const char* pack_name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindPack'", NULL);
#endif
  {
   XFilePackageEasy* tolua_ret = (XFilePackageEasy*)  self->FindPack(pack_name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XFilePackageEasy");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindPack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindPackByFilePath of class  XFilePackManage */
#ifndef TOLUA_DISABLE_tolua_owl_XFilePackManage_FindPackByFilePath00
static int tolua_owl_XFilePackManage_FindPackByFilePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XFilePackManage",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  std::string pathkey = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  {
   const char* tolua_ret = (const char*)  XFilePackManage::FindPackByFilePath(path,pathkey);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)pathkey);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindPackByFilePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tag of class  LogItem */
#ifndef TOLUA_DISABLE_tolua_get_XLog__LogItem_tag
static int tolua_get_XLog__LogItem_tag(lua_State* tolua_S)
{
  XLog::LogItem* self = (XLog::LogItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tag'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->tag);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tag of class  LogItem */
#ifndef TOLUA_DISABLE_tolua_set_XLog__LogItem_tag
static int tolua_set_XLog__LogItem_tag(lua_State* tolua_S)
{
  XLog::LogItem* self = (XLog::LogItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tag'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tag = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: file_name of class  LogItem */
#ifndef TOLUA_DISABLE_tolua_get_XLog__LogItem_file_name
static int tolua_get_XLog__LogItem_file_name(lua_State* tolua_S)
{
  XLog::LogItem* self = (XLog::LogItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'file_name'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->file_name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: file_name of class  LogItem */
#ifndef TOLUA_DISABLE_tolua_set_XLog__LogItem_file_name
static int tolua_set_XLog__LogItem_file_name(lua_State* tolua_S)
{
  XLog::LogItem* self = (XLog::LogItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'file_name'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->file_name = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: file of class  LogItem */
#ifndef TOLUA_DISABLE_tolua_get_XLog__LogItem_file
static int tolua_get_XLog__LogItem_file(lua_State* tolua_S)
{
  XLog::LogItem* self = (XLog::LogItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'file'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->file,"XFile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: file of class  LogItem */
#ifndef TOLUA_DISABLE_tolua_set_XLog__LogItem_file
static int tolua_set_XLog__LogItem_file(lua_State* tolua_S)
{
  XLog::LogItem* self = (XLog::LogItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'file'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"XFile",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->file = *((XFile*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  XLog */
#ifndef TOLUA_DISABLE_tolua_owl_XLog_new00
static int tolua_owl_XLog_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XLog",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XLog* tolua_ret = (XLog*)  Mtolua_new((XLog)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XLog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  XLog */
#ifndef TOLUA_DISABLE_tolua_owl_XLog_new00_local
static int tolua_owl_XLog_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XLog",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XLog* tolua_ret = (XLog*)  Mtolua_new((XLog)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XLog");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  XLog */
#ifndef TOLUA_DISABLE_tolua_owl_XLog_delete00
static int tolua_owl_XLog_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XLog",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XLog* self = (XLog*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get of class  XLog */
#ifndef TOLUA_DISABLE_tolua_owl_XLog_Get00
static int tolua_owl_XLog_Get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XLog",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XLog& tolua_ret = (XLog&)  XLog::Get();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"XLog");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLogDir of class  XLog */
#ifndef TOLUA_DISABLE_tolua_owl_XLog_SetLogDir00
static int tolua_owl_XLog_SetLogDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XLog",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XLog* self = (XLog*)  tolua_tousertype(tolua_S,1,0);
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLogDir'", NULL);
#endif
  {
   self->SetLogDir(path);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLogDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddLogItem of class  XLog */
#ifndef TOLUA_DISABLE_tolua_owl_XLog_AddLogItem00
static int tolua_owl_XLog_AddLogItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XLog",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XLog* self = (XLog*)  tolua_tousertype(tolua_S,1,0);
  const char* tag = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* file_name = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddLogItem'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddLogItem(tag,file_name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddLogItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  XMutex */
#ifndef TOLUA_DISABLE_tolua_owl_XMutex_delete00
static int tolua_owl_XMutex_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XMutex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XMutex* self = (XMutex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lock of class  XMutex */
#ifndef TOLUA_DISABLE_tolua_owl_XMutex_Lock00
static int tolua_owl_XMutex_Lock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XMutex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XMutex* self = (XMutex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lock'", NULL);
#endif
  {
   self->Lock();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lock'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unlock of class  XMutex */
#ifndef TOLUA_DISABLE_tolua_owl_XMutex_Unlock00
static int tolua_owl_XMutex_Unlock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XMutex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XMutex* self = (XMutex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unlock'", NULL);
#endif
  {
   self->Unlock();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Unlock'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: pfnJobProc */
#ifndef TOLUA_DISABLE_tolua_owl_pfnJobProc00
static int tolua_owl_pfnJobProc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XJobDesc",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XJobDesc* parm = ((XJobDesc*)  tolua_tousertype(tolua_S,1,0));
  {
      xint32 tolua_ret = 0;//pfnJobProc(parm);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((xint32)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"xint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(xint32));
     tolua_pushusertype(tolua_S,tolua_obj,"xint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pfnJobProc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  XThread */
#ifndef TOLUA_DISABLE_tolua_owl_XThread_delete00
static int tolua_owl_XThread_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThread",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThread* self = (XThread*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Suppend of class  XThread */
#ifndef TOLUA_DISABLE_tolua_owl_XThread_Suppend00
static int tolua_owl_XThread_Suppend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThread",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThread* self = (XThread*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Suppend'", NULL);
#endif
  {
   self->Suppend();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Suppend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Stop of class  XThread */
#ifndef TOLUA_DISABLE_tolua_owl_XThread_Stop00
static int tolua_owl_XThread_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThread",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThread* self = (XThread*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Stop'", NULL);
#endif
  {
   self->Stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Resume of class  XThread */
#ifndef TOLUA_DISABLE_tolua_owl_XThread_Resume00
static int tolua_owl_XThread_Resume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThread",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThread* self = (XThread*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Resume'", NULL);
#endif
  {
   self->Resume();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Resume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Run of class  XThread */
#ifndef TOLUA_DISABLE_tolua_owl_XThread_Run00
static int tolua_owl_XThread_Run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThread",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThread* self = (XThread*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Run'", NULL);
#endif
  {
   self->Run();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Run'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Join of class  XThread */
#ifndef TOLUA_DISABLE_tolua_owl_XThread_Join00
static int tolua_owl_XThread_Join00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThread",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThread* self = (XThread*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Join'", NULL);
#endif
  {
   self->Join();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Join'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: desc of class  XJob */
#ifndef TOLUA_DISABLE_tolua_get_XJob_desc_ptr
static int tolua_get_XJob_desc_ptr(lua_State* tolua_S)
{
  XJob* self = (XJob*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'desc'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->desc,"XJobDesc");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: desc of class  XJob */
#ifndef TOLUA_DISABLE_tolua_set_XJob_desc_ptr
static int tolua_set_XJob_desc_ptr(lua_State* tolua_S)
{
  XJob* self = (XJob*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'desc'",NULL);
  if (!tolua_isusertype(tolua_S,2,"XJobDesc",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->desc = ((XJobDesc*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: job_proc of class  XJob */
#ifndef TOLUA_DISABLE_tolua_get_XJob_job_proc
static int tolua_get_XJob_job_proc(lua_State* tolua_S)
{
  XJob* self = (XJob*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'job_proc'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->job_proc,"pfnJobProc");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: job_proc of class  XJob */
#ifndef TOLUA_DISABLE_tolua_set_XJob_job_proc
static int tolua_set_XJob_job_proc(lua_State* tolua_S)
{
  XJob* self = (XJob*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'job_proc'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"pfnJobProc",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->job_proc = *((pfnJobProc*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  XJob */
#ifndef TOLUA_DISABLE_tolua_owl_XJob_new00
static int tolua_owl_XJob_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XJob",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XJob* tolua_ret = (XJob*)  Mtolua_new((XJob)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XJob");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  XJob */
#ifndef TOLUA_DISABLE_tolua_owl_XJob_new00_local
static int tolua_owl_XJob_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XJob",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XJob* tolua_ret = (XJob*)  Mtolua_new((XJob)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XJob");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  XThreadPool */
#ifndef TOLUA_DISABLE_tolua_owl_XThreadPool_delete00
static int tolua_owl_XThreadPool_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThreadPool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThreadPool* self = (XThreadPool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateThreadPool of class  XThreadPool */
#ifndef TOLUA_DISABLE_tolua_owl_XThreadPool_CreateThreadPool00
static int tolua_owl_XThreadPool_CreateThreadPool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThreadPool",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThreadPool* self = (XThreadPool*)  tolua_tousertype(tolua_S,1,0);
  int thread_count = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateThreadPool'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->CreateThreadPool(thread_count);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateThreadPool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReleaseThreadPool of class  XThreadPool */
#ifndef TOLUA_DISABLE_tolua_owl_XThreadPool_ReleaseThreadPool00
static int tolua_owl_XThreadPool_ReleaseThreadPool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThreadPool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThreadPool* self = (XThreadPool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReleaseThreadPool'", NULL);
#endif
  {
   self->ReleaseThreadPool();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReleaseThreadPool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PauseThreadPool of class  XThreadPool */
#ifndef TOLUA_DISABLE_tolua_owl_XThreadPool_PauseThreadPool00
static int tolua_owl_XThreadPool_PauseThreadPool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThreadPool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThreadPool* self = (XThreadPool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PauseThreadPool'", NULL);
#endif
  {
   self->PauseThreadPool();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PauseThreadPool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResumeThreadPool of class  XThreadPool */
#ifndef TOLUA_DISABLE_tolua_owl_XThreadPool_ResumeThreadPool00
static int tolua_owl_XThreadPool_ResumeThreadPool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThreadPool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThreadPool* self = (XThreadPool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResumeThreadPool'", NULL);
#endif
  {
   self->ResumeThreadPool();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResumeThreadPool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DoJob of class  XThreadPool */
#ifndef TOLUA_DISABLE_tolua_owl_XThreadPool_DoJob00
static int tolua_owl_XThreadPool_DoJob00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThreadPool",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const XJob",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThreadPool* self = (XThreadPool*)  tolua_tousertype(tolua_S,1,0);
  const XJob* job = ((const XJob*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DoJob'", NULL);
#endif
  {
   self->DoJob(*job);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DoJob'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XLogOutput */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XLogOutput00
static int tolua_owl_XSys_XLogOutput00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* log = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   XSys::XLogOutput(log);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XLogOutput'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XCreateMutex */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XCreateMutex00
static int tolua_owl_XSys_XCreateMutex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XMutex* tolua_ret = (XMutex*)  XSys::XCreateMutex();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XMutex");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XCreateMutex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XDeleteMutex */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XDeleteMutex00
static int tolua_owl_XSys_XDeleteMutex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XMutex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XMutex* tolua_var_1 = ((XMutex*)  tolua_tousertype(tolua_S,1,0));
  {
   XSys::XDeleteMutex(tolua_var_1);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XDeleteMutex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XCreateThread */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XCreateThread00
static int tolua_owl_XSys_XCreateThread00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"pfnJobProc",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,2,"XJobDesc",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  pfnJobProc func = *((pfnJobProc*)  tolua_tousertype(tolua_S,1,0));
  XJobDesc* desc = ((XJobDesc*)  tolua_tousertype(tolua_S,2,0));
  {
   XThread* tolua_ret = (XThread*)  XSys::XCreateThread(func,desc);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XThread");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XCreateThread'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XReleaseThread */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XReleaseThread00
static int tolua_owl_XSys_XReleaseThread00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThread",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThread* tolua_var_2 = ((XThread*)  tolua_tousertype(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  XSys::XReleaseThread(tolua_var_2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XReleaseThread'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XCreateThreadPool */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XCreateThreadPool00
static int tolua_owl_XSys_XCreateThreadPool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int thread_count = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   XThreadPool* tolua_ret = (XThreadPool*)  XSys::XCreateThreadPool(thread_count);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XThreadPool");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XCreateThreadPool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XReleaseThreadPool */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XReleaseThreadPool00
static int tolua_owl_XSys_XReleaseThreadPool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XThreadPool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XThreadPool* tolua_var_3 = ((XThreadPool*)  tolua_tousertype(tolua_S,1,0));
  {
   XSys::XReleaseThreadPool(tolua_var_3);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XReleaseThreadPool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XCreateFile */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XCreateFile00
static int tolua_owl_XSys_XCreateFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* file_path = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  XSys::XCreateFile(file_path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XCreateFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XIsFileExist */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XIsFileExist00
static int tolua_owl_XSys_XIsFileExist00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* file_path = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  XSys::XIsFileExist(file_path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XIsFileExist'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XIsDirectory */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XIsDirectory00
static int tolua_owl_XSys_XIsDirectory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  XSys::XIsDirectory(path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XIsDirectory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XCreateDirectory */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XCreateDirectory00
static int tolua_owl_XSys_XCreateDirectory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  XSys::XCreateDirectory(path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XCreateDirectory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XDeleteFile */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XDeleteFile00
static int tolua_owl_XSys_XDeleteFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  XSys::XDeleteFile(path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XDeleteFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XDeleteDirectory */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XDeleteDirectory00
static int tolua_owl_XSys_XDeleteDirectory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool bIsSubDelAll = ((bool)  tolua_toboolean(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  XSys::XDeleteDirectory(path,bIsSubDelAll);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XDeleteDirectory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XSetFileSize */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XSetFileSize00
static int tolua_owl_XSys_XSetFileSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,1,0));
  long size = ((long)  tolua_tonumber(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  XSys::XSetFileSize(path,size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XSetFileSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XSetFileSize */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XSetFileSize01
static int tolua_owl_XSys_XSetFileSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FILE",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FILE* fp = ((FILE*)  tolua_tousertype(tolua_S,1,0));
  long size = ((long)  tolua_tonumber(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  XSys::XSetFileSize(fp,size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_owl_XSys_XSetFileSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: XSys::XFileNo */
#ifndef TOLUA_DISABLE_tolua_owl_XSys_XFileNo00
static int tolua_owl_XSys_XFileNo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FILE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FILE* fp = ((FILE*)  tolua_tousertype(tolua_S,1,0));
  {
   int tolua_ret = (int)  XSys::XFileNo(fp);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XFileNo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: main_version of class  AssetVersion */
#ifndef TOLUA_DISABLE_tolua_get_AssetVersion_main_version
static int tolua_get_AssetVersion_main_version(lua_State* tolua_S)
{
  AssetVersion* self = (AssetVersion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'main_version'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->main_version);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: main_version of class  AssetVersion */
#ifndef TOLUA_DISABLE_tolua_set_AssetVersion_main_version
static int tolua_set_AssetVersion_main_version(lua_State* tolua_S)
{
  AssetVersion* self = (AssetVersion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'main_version'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->main_version = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sub_version of class  AssetVersion */
#ifndef TOLUA_DISABLE_tolua_get_AssetVersion_sub_version
static int tolua_get_AssetVersion_sub_version(lua_State* tolua_S)
{
  AssetVersion* self = (AssetVersion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sub_version'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->sub_version);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sub_version of class  AssetVersion */
#ifndef TOLUA_DISABLE_tolua_set_AssetVersion_sub_version
static int tolua_set_AssetVersion_sub_version(lua_State* tolua_S)
{
  AssetVersion* self = (AssetVersion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sub_version'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sub_version = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: asset_version of class  AssetVersion */
#ifndef TOLUA_DISABLE_tolua_get_AssetVersion_asset_version
static int tolua_get_AssetVersion_asset_version(lua_State* tolua_S)
{
  AssetVersion* self = (AssetVersion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'asset_version'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->asset_version);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: asset_version of class  AssetVersion */
#ifndef TOLUA_DISABLE_tolua_set_AssetVersion_asset_version
static int tolua_set_AssetVersion_asset_version(lua_State* tolua_S)
{
  AssetVersion* self = (AssetVersion*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'asset_version'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->asset_version = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: event_type of class  PatcherEvent */
#ifndef TOLUA_DISABLE_tolua_get_PatcherEvent_event_type
static int tolua_get_PatcherEvent_event_type(lua_State* tolua_S)
{
  PatcherEvent* self = (PatcherEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'event_type'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->event_type);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: event_type of class  PatcherEvent */
#ifndef TOLUA_DISABLE_tolua_set_PatcherEvent_event_type
static int tolua_set_PatcherEvent_event_type(lua_State* tolua_S)
{
  PatcherEvent* self = (PatcherEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'event_type'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->event_type = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: parm1 of class  PatcherEvent */
#ifndef TOLUA_DISABLE_tolua_get_PatcherEvent_parm1
static int tolua_get_PatcherEvent_parm1(lua_State* tolua_S)
{
  PatcherEvent* self = (PatcherEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parm1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->parm1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parm1 of class  PatcherEvent */
#ifndef TOLUA_DISABLE_tolua_set_PatcherEvent_parm1
static int tolua_set_PatcherEvent_parm1(lua_State* tolua_S)
{
  PatcherEvent* self = (PatcherEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parm1'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->parm1 = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: parm2 of class  PatcherEvent */
#ifndef TOLUA_DISABLE_tolua_get_PatcherEvent_parm2
static int tolua_get_PatcherEvent_parm2(lua_State* tolua_S)
{
  PatcherEvent* self = (PatcherEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parm2'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->parm2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parm2 of class  PatcherEvent */
#ifndef TOLUA_DISABLE_tolua_set_PatcherEvent_parm2
static int tolua_set_PatcherEvent_parm2(lua_State* tolua_S)
{
  PatcherEvent* self = (PatcherEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parm2'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->parm2 = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: parm3 of class  PatcherEvent */
#ifndef TOLUA_DISABLE_tolua_get_PatcherEvent_parm3
static int tolua_get_PatcherEvent_parm3(lua_State* tolua_S)
{
  PatcherEvent* self = (PatcherEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parm3'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->parm3);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parm3 of class  PatcherEvent */
#ifndef TOLUA_DISABLE_tolua_set_PatcherEvent_parm3
static int tolua_set_PatcherEvent_parm3(lua_State* tolua_S)
{
  PatcherEvent* self = (PatcherEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parm3'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->parm3 = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cur_version of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_get_PatcherState_cur_version
static int tolua_get_PatcherState_cur_version(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cur_version'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->cur_version,"AssetVersion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cur_version of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_set_PatcherState_cur_version
static int tolua_set_PatcherState_cur_version(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cur_version'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AssetVersion",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cur_version = *((AssetVersion*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: target_version of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_get_PatcherState_target_version
static int tolua_get_PatcherState_target_version(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'target_version'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->target_version,"AssetVersion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: target_version of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_set_PatcherState_target_version
static int tolua_set_PatcherState_target_version(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'target_version'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AssetVersion",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->target_version = *((AssetVersion*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: state of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_get_PatcherState_state
static int tolua_get_PatcherState_state(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'state'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->state);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: state of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_set_PatcherState_state
static int tolua_set_PatcherState_state(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'state'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->state = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: is_complete of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_get_PatcherState_is_complete
static int tolua_get_PatcherState_is_complete(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'is_complete'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->is_complete);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: is_complete of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_set_PatcherState_is_complete
static int tolua_set_PatcherState_is_complete(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'is_complete'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->is_complete = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: total_length of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_get_PatcherState_total_length
static int tolua_get_PatcherState_total_length(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'total_length'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->total_length);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: total_length of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_set_PatcherState_total_length
static int tolua_set_PatcherState_total_length(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'total_length'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->total_length = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: getted_length of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_get_PatcherState_getted_length
static int tolua_get_PatcherState_getted_length(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'getted_length'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->getted_length);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: getted_length of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_set_PatcherState_getted_length
static int tolua_set_PatcherState_getted_length(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'getted_length'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->getted_length = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cur_index of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_get_PatcherState_cur_index
static int tolua_get_PatcherState_cur_index(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cur_index'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cur_index);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cur_index of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_set_PatcherState_cur_index
static int tolua_set_PatcherState_cur_index(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cur_index'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cur_index = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: total_count of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_get_PatcherState_total_count
static int tolua_get_PatcherState_total_count(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'total_count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->total_count);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: total_count of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_set_PatcherState_total_count
static int tolua_set_PatcherState_total_count(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'total_count'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->total_count = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: real_speed of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_get_PatcherState_real_speed
static int tolua_get_PatcherState_real_speed(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'real_speed'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->real_speed);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: real_speed of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_set_PatcherState_real_speed
static int tolua_set_PatcherState_real_speed(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'real_speed'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->real_speed = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: apply_index of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_get_PatcherState_apply_index
static int tolua_get_PatcherState_apply_index(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'apply_index'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->apply_index);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: apply_index of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_set_PatcherState_apply_index
static int tolua_set_PatcherState_apply_index(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'apply_index'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->apply_index = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: total_apply of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_get_PatcherState_total_apply
static int tolua_get_PatcherState_total_apply(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'total_apply'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->total_apply);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: total_apply of class  PatcherState */
#ifndef TOLUA_DISABLE_tolua_set_PatcherState_total_apply
static int tolua_set_PatcherState_total_apply(lua_State* tolua_S)
{
  PatcherState* self = (PatcherState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'total_apply'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->total_apply = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_new00
static int tolua_owl_XPatcher_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XPatcher* tolua_ret = (XPatcher*)  Mtolua_new((XPatcher)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XPatcher");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_new00_local
static int tolua_owl_XPatcher_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XPatcher* tolua_ret = (XPatcher*)  Mtolua_new((XPatcher)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XPatcher");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_delete00
static int tolua_owl_XPatcher_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPatcher* self = (XPatcher*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInstance of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_GetInstance00
static int tolua_owl_XPatcher_GetInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XPatcher* tolua_ret = (XPatcher*)  XPatcher::GetInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XPatcher");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_Init00
static int tolua_owl_XPatcher_Init00(lua_State* tolua_S)
{
return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: TrigEvent of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_TrigEvent00
static int tolua_owl_XPatcher_TrigEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPatcher",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const PatcherEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPatcher* self = (XPatcher*)  tolua_tousertype(tolua_S,1,0);
  const PatcherEvent* pe = ((const PatcherEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TrigEvent'", NULL);
#endif
  {
   self->TrigEvent(*pe);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TrigEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StartPatch of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_StartPatch00
static int tolua_owl_XPatcher_StartPatch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPatcher* self = (XPatcher*)  tolua_tousertype(tolua_S,1,0);
  const char* patch_url = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StartPatch'", NULL);
#endif
  {
   self->StartPatch(patch_url);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StartPatch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: QueryPatcherState of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_QueryPatcherState00
static int tolua_owl_XPatcher_QueryPatcherState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPatcher* self = (XPatcher*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'QueryPatcherState'", NULL);
#endif
  {
   PatcherState tolua_ret = (PatcherState)  self->QueryPatcherState();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((PatcherState)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"PatcherState");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(PatcherState));
     tolua_pushusertype(tolua_S,tolua_obj,"PatcherState");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'QueryPatcherState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DownloadFile of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_DownloadFile00
static int tolua_owl_XPatcher_DownloadFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPatcher* self = (XPatcher*)  tolua_tousertype(tolua_S,1,0);
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* dest_file = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DownloadFile'", NULL);
#endif
  {
   self->DownloadFile(url,dest_file);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DownloadFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DownloadFile of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_DownloadFile01
static int tolua_owl_XPatcher_DownloadFile01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"pfnDownloadCallback",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  XPatcher* self = (XPatcher*)  tolua_tousertype(tolua_S,1,0);
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* dest_file = ((const char*)  tolua_tostring(tolua_S,3,0));
  pfnDownloadCallback func = *((pfnDownloadCallback*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DownloadFile'", NULL);
#endif
  {
   self->DownloadFile(url,dest_file,func);
  }
 }
 return 0;
tolua_lerror:
 return tolua_owl_XPatcher_DownloadFile00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UploadFile of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_UploadFile00
static int tolua_owl_XPatcher_UploadFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"pfnUploadCallback",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPatcher* self = (XPatcher*)  tolua_tousertype(tolua_S,1,0);
  const char* src_file = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* url = ((const char*)  tolua_tostring(tolua_S,3,0));
  pfnUploadCallback func = *((pfnUploadCallback*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UploadFile'", NULL);
#endif
  {
   self->UploadFile(src_file,url,func);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UploadFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PatchProc of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_PatchProc00
static int tolua_owl_XPatcher_PatchProc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPatcher* self = (XPatcher*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PatchProc'", NULL);
#endif
  {
   self->PatchProc();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PatchProc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DownloadPathCallBack of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_DownloadPathCallBack00
static int tolua_owl_XPatcher_DownloadPathCallBack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPatcher* self = (XPatcher*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  int downloaded = ((int)  tolua_tonumber(tolua_S,3,0));
  int total = ((int)  tolua_tonumber(tolua_S,4,0));
  int speed = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DownloadPathCallBack'", NULL);
#endif
  {
   self->DownloadPathCallBack(data,downloaded,total,speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DownloadPathCallBack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyPatchCallBack of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_ApplyPatchCallBack00
static int tolua_owl_XPatcher_ApplyPatchCallBack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPatcher* self = (XPatcher*)  tolua_tousertype(tolua_S,1,0);
  int cur_apply = ((int)  tolua_tonumber(tolua_S,2,0));
  int total_apply = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyPatchCallBack'", NULL);
#endif
  {
   self->ApplyPatchCallBack(cur_apply,total_apply);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyPatchCallBack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clean of class  XPatcher */
#ifndef TOLUA_DISABLE_tolua_owl_XPatcher_Clean00
static int tolua_owl_XPatcher_Clean00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPatcher",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPatcher* self = (XPatcher*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clean'", NULL);
#endif
  {
   self->Clean();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clean'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInstance of class  XPathMon */
#ifndef TOLUA_DISABLE_tolua_owl_XPathMon_GetInstance00
static int tolua_owl_XPathMon_GetInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XPathMon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XPathMon& tolua_ret = (XPathMon&)  XPathMon::GetInstance();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"XPathMon");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  XPathMon */
#ifndef TOLUA_DISABLE_tolua_owl_XPathMon_Init00
static int tolua_owl_XPathMon_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPathMon",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPathMon* self = (XPathMon*)  tolua_tousertype(tolua_S,1,0);
  const char* writable_path = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* bundle_path = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Init(writable_path,bundle_path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddPath of class  XPathMon */
#ifndef TOLUA_DISABLE_tolua_owl_XPathMon_AddPath00
static int tolua_owl_XPathMon_AddPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPathMon",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPathMon* self = (XPathMon*)  tolua_tousertype(tolua_S,1,0);
  const char* tag = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* full_path = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPath'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddPath(tag,full_path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPathByTag of class  XPathMon */
#ifndef TOLUA_DISABLE_tolua_owl_XPathMon_GetPathByTag00
static int tolua_owl_XPathMon_GetPathByTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XPathMon",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XPathMon* self = (const XPathMon*)  tolua_tousertype(tolua_S,1,0);
  const char* tag = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPathByTag'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetPathByTag(tag);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPathByTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWritablePath of class  XPathMon */
#ifndef TOLUA_DISABLE_tolua_owl_XPathMon_GetWritablePath00
static int tolua_owl_XPathMon_GetWritablePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XPathMon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XPathMon* self = (const XPathMon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWritablePath'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetWritablePath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWritablePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBundlePath of class  XPathMon */
#ifndef TOLUA_DISABLE_tolua_owl_XPathMon_GetBundlePath00
static int tolua_owl_XPathMon_GetBundlePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XPathMon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XPathMon* self = (const XPathMon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBundlePath'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetBundlePath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBundlePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInitAssetPath of class  XPathMon */
#ifndef TOLUA_DISABLE_tolua_owl_XPathMon_GetInitAssetPath00
static int tolua_owl_XPathMon_GetInitAssetPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XPathMon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XPathMon* self = (const XPathMon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInitAssetPath'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetInitAssetPath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInitAssetPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAssetUpdatePath of class  XPathMon */
#ifndef TOLUA_DISABLE_tolua_owl_XPathMon_GetAssetUpdatePath00
static int tolua_owl_XPathMon_GetAssetUpdatePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XPathMon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XPathMon* self = (const XPathMon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAssetUpdatePath'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetAssetUpdatePath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAssetUpdatePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTmpPath of class  XPathMon */
#ifndef TOLUA_DISABLE_tolua_owl_XPathMon_GetTmpPath00
static int tolua_owl_XPathMon_GetTmpPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XPathMon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XPathMon* self = (const XPathMon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTmpPath'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetTmpPath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTmpPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGameDataPath of class  XPathMon */
#ifndef TOLUA_DISABLE_tolua_owl_XPathMon_GetGameDataPath00
static int tolua_owl_XPathMon_GetGameDataPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XPathMon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XPathMon* self = (XPathMon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGameDataPath'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetGameDataPath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGameDataPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLogPath of class  XPathMon */
#ifndef TOLUA_DISABLE_tolua_owl_XPathMon_GetLogPath00
static int tolua_owl_XPathMon_GetLogPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XPathMon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XPathMon* self = (const XPathMon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLogPath'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetLogPath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLogPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_owl_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"XFileGroup","XFileGroup","",NULL);
  tolua_beginmodule(tolua_S,"XFileGroup");
   tolua_function(tolua_S,"getFileData",tolua_owl_XFileGroup_getFileData00);
   tolua_function(tolua_S,"GetBundlePackMan",tolua_owl_XFileGroup_GetBundlePackMan00);
   tolua_function(tolua_S,"GetUpdatePackMan",tolua_owl_XFileGroup_GetUpdatePackMan00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"FPK_COUNT",FPK_COUNT);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"XFilePackManage","XFilePackManage","",tolua_collect_XFilePackManage);
  #else
  tolua_cclass(tolua_S,"XFilePackManage","XFilePackManage","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"XFilePackManage");
   tolua_cclass(tolua_S,"FilePackItem","XFilePackManage::FilePackItem","",NULL);
   tolua_beginmodule(tolua_S,"FilePackItem");
    tolua_variable(tolua_S,"pack_name",tolua_get_XFilePackManage__FilePackItem_pack_name,tolua_set_XFilePackManage__FilePackItem_pack_name);
    tolua_variable(tolua_S,"file_pack_easy",tolua_get_XFilePackManage__FilePackItem_file_pack_easy_ptr,tolua_set_XFilePackManage__FilePackItem_file_pack_easy_ptr);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"new",tolua_owl_XFilePackManage_new00);
   tolua_function(tolua_S,"new_local",tolua_owl_XFilePackManage_new00_local);
   tolua_function(tolua_S,".call",tolua_owl_XFilePackManage_new00_local);
   tolua_function(tolua_S,"Get",tolua_owl_XFilePackManage_Get00);
   tolua_function(tolua_S,"InitPackMan",tolua_owl_XFilePackManage_InitPackMan00);
   tolua_function(tolua_S,"AddPack",tolua_owl_XFilePackManage_AddPack00);
   tolua_function(tolua_S,"AddFile",tolua_owl_XFilePackManage_AddFile00);
   tolua_function(tolua_S,"DelFile",tolua_owl_XFilePackManage_DelFile00);
   tolua_function(tolua_S,"ModFile",tolua_owl_XFilePackManage_ModFile00);
   tolua_function(tolua_S,"FindPack",tolua_owl_XFilePackManage_FindPack00);
   tolua_function(tolua_S,"FindPackByFilePath",tolua_owl_XFilePackManage_FindPackByFilePath00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"XLog","XLog","",tolua_collect_XLog);
  #else
  tolua_cclass(tolua_S,"XLog","XLog","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"XLog");
   tolua_cclass(tolua_S,"LogItem","XLog::LogItem","",NULL);
   tolua_beginmodule(tolua_S,"LogItem");
    tolua_variable(tolua_S,"tag",tolua_get_XLog__LogItem_tag,tolua_set_XLog__LogItem_tag);
    tolua_variable(tolua_S,"file_name",tolua_get_XLog__LogItem_file_name,tolua_set_XLog__LogItem_file_name);
    tolua_variable(tolua_S,"file",tolua_get_XLog__LogItem_file,tolua_set_XLog__LogItem_file);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"new",tolua_owl_XLog_new00);
   tolua_function(tolua_S,"new_local",tolua_owl_XLog_new00_local);
   tolua_function(tolua_S,".call",tolua_owl_XLog_new00_local);
   tolua_function(tolua_S,"delete",tolua_owl_XLog_delete00);
   tolua_function(tolua_S,"Get",tolua_owl_XLog_Get00);
   tolua_function(tolua_S,"SetLogDir",tolua_owl_XLog_SetLogDir00);
   tolua_function(tolua_S,"AddLogItem",tolua_owl_XLog_AddLogItem00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"XMutex","XMutex","",tolua_collect_XMutex);
  #else
  tolua_cclass(tolua_S,"XMutex","XMutex","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"XMutex");
   tolua_function(tolua_S,"delete",tolua_owl_XMutex_delete00);
   tolua_function(tolua_S,"Lock",tolua_owl_XMutex_Lock00);
   tolua_function(tolua_S,"Unlock",tolua_owl_XMutex_Unlock00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"XEvent","XEvent","",NULL);
  tolua_beginmodule(tolua_S,"XEvent");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"XJobDesc","XJobDesc","",NULL);
  tolua_beginmodule(tolua_S,"XJobDesc");
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"pfnJobProc",tolua_owl_pfnJobProc00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"XThread","XThread","",tolua_collect_XThread);
  #else
  tolua_cclass(tolua_S,"XThread","XThread","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"XThread");
   tolua_constant(tolua_S,"LOWER_PRIORITY",XThread::LOWER_PRIORITY);
   tolua_constant(tolua_S,"NORMAL_PRIORITY",XThread::NORMAL_PRIORITY);
   tolua_constant(tolua_S,"HIGH_PRIORITY",XThread::HIGH_PRIORITY);
   tolua_constant(tolua_S,"PRIORITY_NUM",XThread::PRIORITY_NUM);
   tolua_function(tolua_S,"delete",tolua_owl_XThread_delete00);
   tolua_function(tolua_S,"Suppend",tolua_owl_XThread_Suppend00);
   tolua_function(tolua_S,"Stop",tolua_owl_XThread_Stop00);
   tolua_function(tolua_S,"Resume",tolua_owl_XThread_Resume00);
   tolua_function(tolua_S,"Run",tolua_owl_XThread_Run00);
   tolua_function(tolua_S,"Join",tolua_owl_XThread_Join00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"XJob","XJob","",tolua_collect_XJob);
  #else
  tolua_cclass(tolua_S,"XJob","XJob","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"XJob");
   tolua_variable(tolua_S,"desc",tolua_get_XJob_desc_ptr,tolua_set_XJob_desc_ptr);
   tolua_variable(tolua_S,"job_proc",tolua_get_XJob_job_proc,tolua_set_XJob_job_proc);
   tolua_function(tolua_S,"new",tolua_owl_XJob_new00);
   tolua_function(tolua_S,"new_local",tolua_owl_XJob_new00_local);
   tolua_function(tolua_S,".call",tolua_owl_XJob_new00_local);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"XThreadPool","XThreadPool","",tolua_collect_XThreadPool);
  #else
  tolua_cclass(tolua_S,"XThreadPool","XThreadPool","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"XThreadPool");
   tolua_constant(tolua_S,"RUN_EVENT",XThreadPool::RUN_EVENT);
   tolua_constant(tolua_S,"PAUSE_EVENT",XThreadPool::PAUSE_EVENT);
   tolua_constant(tolua_S,"EXIT_EVENT",XThreadPool::EXIT_EVENT);
   tolua_constant(tolua_S,"EVENT_NUM",XThreadPool::EVENT_NUM);
   tolua_function(tolua_S,"delete",tolua_owl_XThreadPool_delete00);
   tolua_function(tolua_S,"CreateThreadPool",tolua_owl_XThreadPool_CreateThreadPool00);
   tolua_function(tolua_S,"ReleaseThreadPool",tolua_owl_XThreadPool_ReleaseThreadPool00);
   tolua_function(tolua_S,"PauseThreadPool",tolua_owl_XThreadPool_PauseThreadPool00);
   tolua_function(tolua_S,"ResumeThreadPool",tolua_owl_XThreadPool_ResumeThreadPool00);
   tolua_function(tolua_S,"DoJob",tolua_owl_XThreadPool_DoJob00);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"XSys",0);
  tolua_beginmodule(tolua_S,"XSys");
   tolua_function(tolua_S,"XLogOutput",tolua_owl_XSys_XLogOutput00);
   tolua_function(tolua_S,"XCreateMutex",tolua_owl_XSys_XCreateMutex00);
   tolua_function(tolua_S,"XDeleteMutex",tolua_owl_XSys_XDeleteMutex00);
   tolua_function(tolua_S,"XCreateThread",tolua_owl_XSys_XCreateThread00);
   tolua_function(tolua_S,"XReleaseThread",tolua_owl_XSys_XReleaseThread00);
   tolua_function(tolua_S,"XCreateThreadPool",tolua_owl_XSys_XCreateThreadPool00);
   tolua_function(tolua_S,"XReleaseThreadPool",tolua_owl_XSys_XReleaseThreadPool00);
   tolua_function(tolua_S,"XCreateFile",tolua_owl_XSys_XCreateFile00);
   tolua_function(tolua_S,"XIsFileExist",tolua_owl_XSys_XIsFileExist00);
   tolua_function(tolua_S,"XIsDirectory",tolua_owl_XSys_XIsDirectory00);
   tolua_function(tolua_S,"XCreateDirectory",tolua_owl_XSys_XCreateDirectory00);
   tolua_function(tolua_S,"XDeleteFile",tolua_owl_XSys_XDeleteFile00);
   tolua_function(tolua_S,"XDeleteDirectory",tolua_owl_XSys_XDeleteDirectory00);
   tolua_function(tolua_S,"XSetFileSize",tolua_owl_XSys_XSetFileSize00);
   tolua_function(tolua_S,"XSetFileSize",tolua_owl_XSys_XSetFileSize01);
   tolua_function(tolua_S,"XFileNo",tolua_owl_XSys_XFileNo00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"PS_UNKONW",PS_UNKONW);
  tolua_constant(tolua_S,"PS_NDS_ERROR",PS_NDS_ERROR);
  tolua_constant(tolua_S,"PS_LOCAL_ASSET_BROKEN",PS_LOCAL_ASSET_BROKEN);
  tolua_constant(tolua_S,"PS_ASSET_BROKEN",PS_ASSET_BROKEN);
  tolua_constant(tolua_S,"PS_NETWORK_EXCEPTION",PS_NETWORK_EXCEPTION);
  tolua_constant(tolua_S,"PS_APPVER_ERROR",PS_APPVER_ERROR);
  tolua_constant(tolua_S,"PS_CHECK_NETOWRK",PS_CHECK_NETOWRK);
  tolua_constant(tolua_S,"PS_CHECK_VERSION",PS_CHECK_VERSION);
  tolua_constant(tolua_S,"PS_DOWNLOAD_PATCH",PS_DOWNLOAD_PATCH);
  tolua_constant(tolua_S,"PS_APPLY_PATCH",PS_APPLY_PATCH);
  tolua_constant(tolua_S,"PS_PATCH_ERROR",PS_PATCH_ERROR);
  tolua_constant(tolua_S,"PS_FINISH",PS_FINISH);
  tolua_cclass(tolua_S,"AssetVersion","AssetVersion","",NULL);
  tolua_beginmodule(tolua_S,"AssetVersion");
   tolua_variable(tolua_S,"main_version",tolua_get_AssetVersion_main_version,tolua_set_AssetVersion_main_version);
   tolua_variable(tolua_S,"sub_version",tolua_get_AssetVersion_sub_version,tolua_set_AssetVersion_sub_version);
   tolua_variable(tolua_S,"asset_version",tolua_get_AssetVersion_asset_version,tolua_set_AssetVersion_asset_version);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"PatcherEvent","PatcherEvent","",NULL);
  tolua_beginmodule(tolua_S,"PatcherEvent");
   tolua_variable(tolua_S,"event_type",tolua_get_PatcherEvent_event_type,tolua_set_PatcherEvent_event_type);
   tolua_variable(tolua_S,"parm1",tolua_get_PatcherEvent_parm1,tolua_set_PatcherEvent_parm1);
   tolua_variable(tolua_S,"parm2",tolua_get_PatcherEvent_parm2,tolua_set_PatcherEvent_parm2);
   tolua_variable(tolua_S,"parm3",tolua_get_PatcherEvent_parm3,tolua_set_PatcherEvent_parm3);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"PatcherState","PatcherState","",tolua_collect_PatcherState);
  #else
  tolua_cclass(tolua_S,"PatcherState","PatcherState","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"PatcherState");
   tolua_variable(tolua_S,"cur_version",tolua_get_PatcherState_cur_version,tolua_set_PatcherState_cur_version);
   tolua_variable(tolua_S,"target_version",tolua_get_PatcherState_target_version,tolua_set_PatcherState_target_version);
   tolua_variable(tolua_S,"state",tolua_get_PatcherState_state,tolua_set_PatcherState_state);
   tolua_variable(tolua_S,"is_complete",tolua_get_PatcherState_is_complete,tolua_set_PatcherState_is_complete);
   tolua_variable(tolua_S,"total_length",tolua_get_PatcherState_total_length,tolua_set_PatcherState_total_length);
   tolua_variable(tolua_S,"getted_length",tolua_get_PatcherState_getted_length,tolua_set_PatcherState_getted_length);
   tolua_variable(tolua_S,"cur_index",tolua_get_PatcherState_cur_index,tolua_set_PatcherState_cur_index);
   tolua_variable(tolua_S,"total_count",tolua_get_PatcherState_total_count,tolua_set_PatcherState_total_count);
   tolua_variable(tolua_S,"real_speed",tolua_get_PatcherState_real_speed,tolua_set_PatcherState_real_speed);
   tolua_variable(tolua_S,"apply_index",tolua_get_PatcherState_apply_index,tolua_set_PatcherState_apply_index);
   tolua_variable(tolua_S,"total_apply",tolua_get_PatcherState_total_apply,tolua_set_PatcherState_total_apply);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"XPatcher","XPatcher","",tolua_collect_XPatcher);
  #else
  tolua_cclass(tolua_S,"XPatcher","XPatcher","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"XPatcher");
   tolua_function(tolua_S,"new",tolua_owl_XPatcher_new00);
   tolua_function(tolua_S,"new_local",tolua_owl_XPatcher_new00_local);
   tolua_function(tolua_S,".call",tolua_owl_XPatcher_new00_local);
   tolua_function(tolua_S,"delete",tolua_owl_XPatcher_delete00);
   tolua_function(tolua_S,"GetInstance",tolua_owl_XPatcher_GetInstance00);
   tolua_function(tolua_S,"Init",tolua_owl_XPatcher_Init00);
   tolua_function(tolua_S,"TrigEvent",tolua_owl_XPatcher_TrigEvent00);
   tolua_function(tolua_S,"StartPatch",tolua_owl_XPatcher_StartPatch00);
   tolua_function(tolua_S,"QueryPatcherState",tolua_owl_XPatcher_QueryPatcherState00);
   tolua_function(tolua_S,"DownloadFile",tolua_owl_XPatcher_DownloadFile00);
   tolua_function(tolua_S,"DownloadFile",tolua_owl_XPatcher_DownloadFile01);
   tolua_function(tolua_S,"UploadFile",tolua_owl_XPatcher_UploadFile00);
   tolua_function(tolua_S,"PatchProc",tolua_owl_XPatcher_PatchProc00);
   tolua_function(tolua_S,"DownloadPathCallBack",tolua_owl_XPatcher_DownloadPathCallBack00);
   tolua_function(tolua_S,"ApplyPatchCallBack",tolua_owl_XPatcher_ApplyPatchCallBack00);
   tolua_function(tolua_S,"Clean",tolua_owl_XPatcher_Clean00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"XPathMon","XPathMon","",NULL);
  tolua_beginmodule(tolua_S,"XPathMon");
   tolua_function(tolua_S,"GetInstance",tolua_owl_XPathMon_GetInstance00);
   tolua_function(tolua_S,"Init",tolua_owl_XPathMon_Init00);
   tolua_function(tolua_S,"AddPath",tolua_owl_XPathMon_AddPath00);
   tolua_function(tolua_S,"GetPathByTag",tolua_owl_XPathMon_GetPathByTag00);
   tolua_function(tolua_S,"GetWritablePath",tolua_owl_XPathMon_GetWritablePath00);
   tolua_function(tolua_S,"GetBundlePath",tolua_owl_XPathMon_GetBundlePath00);
   tolua_function(tolua_S,"GetInitAssetPath",tolua_owl_XPathMon_GetInitAssetPath00);
   tolua_function(tolua_S,"GetAssetUpdatePath",tolua_owl_XPathMon_GetAssetUpdatePath00);
   tolua_function(tolua_S,"GetTmpPath",tolua_owl_XPathMon_GetTmpPath00);
   tolua_function(tolua_S,"GetGameDataPath",tolua_owl_XPathMon_GetGameDataPath00);
   tolua_function(tolua_S,"GetLogPath",tolua_owl_XPathMon_GetLogPath00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_owl (lua_State* tolua_S) {
 return tolua_owl_open(tolua_S);
};
#endif

