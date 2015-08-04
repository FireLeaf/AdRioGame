/*
** Lua binding: owl
** Generated automatically by tolua++-1.0.92 on 08/04/15 14:35:09.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_owl_open (lua_State* tolua_S);

#include "XFileGroup.h"
#include "XFilePackManager.h"
#include "XLog.h"
include"XMD5.h"
#include"XSys.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_XJob (lua_State* tolua_S)
{
 XJob* self = (XJob*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_XThreadPool (lua_State* tolua_S)
{
 XThreadPool* self = (XThreadPool*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_XThread (lua_State* tolua_S)
{
 XThread* self = (XThread*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_xint32 (lua_State* tolua_S)
{
 xint32* self = (xint32*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"XFile");
 tolua_usertype(tolua_S,"XEvent");
 tolua_usertype(tolua_S,"MD5_CTX");
 tolua_usertype(tolua_S,"XLog");
 tolua_usertype(tolua_S,"XFilePackManage::FilePackItem");
 tolua_usertype(tolua_S,"XFileGroup");
 tolua_usertype(tolua_S,"FILE");
 tolua_usertype(tolua_S,"pfnJobProc");
 tolua_usertype(tolua_S,"xint32");
 tolua_usertype(tolua_S,"XFilePackageEasy");
 tolua_usertype(tolua_S,"XThreadPool");
 tolua_usertype(tolua_S,"XLog::LogItem");
 tolua_usertype(tolua_S,"XJob");
 tolua_usertype(tolua_S,"XJobDesc");
 tolua_usertype(tolua_S,"XMutex");
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

/* function: MD5Init */
#ifndef TOLUA_DISABLE_tolua_owl_MD5Init00
static int tolua_owl_MD5Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MD5_CTX",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MD5_CTX* context = ((MD5_CTX*)  tolua_tousertype(tolua_S,1,0));
  {
   MD5Init(context);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MD5Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: MD5Update */
#ifndef TOLUA_DISABLE_tolua_owl_MD5Update00
static int tolua_owl_MD5Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MD5_CTX",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MD5_CTX* context = ((MD5_CTX*)  tolua_tousertype(tolua_S,1,0));
  unsigned char* input = ((unsigned char*)  tolua_tostring(tolua_S,2,0));
  unsigned int inputLen = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   MD5Update(context,input,inputLen);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MD5Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: MD5UpdaterString */
#ifndef TOLUA_DISABLE_tolua_owl_MD5UpdaterString00
static int tolua_owl_MD5UpdaterString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MD5_CTX",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MD5_CTX* context = ((MD5_CTX*)  tolua_tousertype(tolua_S,1,0));
  _cstring const string tolua_var_1 = ((_cstring const string)  tolua_tocppstring(tolua_S,2,0));
  {
   MD5UpdaterString(context,tolua_var_1);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MD5UpdaterString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: MD5FileUpdateFile */
#ifndef TOLUA_DISABLE_tolua_owl_MD5FileUpdateFile00
static int tolua_owl_MD5FileUpdateFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MD5_CTX",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MD5_CTX* context = ((MD5_CTX*)  tolua_tousertype(tolua_S,1,0));
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  {
   int tolua_ret = (int)  MD5FileUpdateFile(context,filename);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MD5FileUpdateFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: MD5Final */
#ifndef TOLUA_DISABLE_tolua_owl_MD5Final00
static int tolua_owl_MD5Final00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_istable(tolua_S,1,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MD5_CTX",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned char* digest[16];
  MD5_CTX* context = ((MD5_CTX*)  tolua_tousertype(tolua_S,2,0));
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isstringarray(tolua_S,1,16,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<16;i++)
    digest[i] = ((char*)  tolua_tofieldstring(tolua_S,1,i+1,0));
   }
  }
  {
   MD5Final(digest,context);
  }
  {
   int i;
   for(i=0; i<16;i++)
    tolua_pushfieldstring(tolua_S,1,i+1,(const char*) digest[i]);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MD5Final'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: MDString */
#ifndef TOLUA_DISABLE_tolua_owl_MDString00
static int tolua_owl_MDString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_iscppstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  _cstring string tolua_var_2 = ((_cstring string)  tolua_tocppstring(tolua_S,1,0));
  unsigned char* digest[16];
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isstringarray(tolua_S,2,16,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<16;i++)
    digest[i] = ((char*)  tolua_tofieldstring(tolua_S,2,i+1,0));
   }
  }
  {
   MDString(tolua_var_2,digest);
  }
  {
   int i;
   for(i=0; i<16;i++)
    tolua_pushfieldstring(tolua_S,2,i+1,(const char*) digest[i]);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MDString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: MD5File */
#ifndef TOLUA_DISABLE_tolua_owl_MD5File00
static int tolua_owl_MD5File00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,1,0));
  unsigned char* digest[16];
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isstringarray(tolua_S,2,16,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<16;i++)
    digest[i] = ((char*)  tolua_tofieldstring(tolua_S,2,i+1,0));
   }
  }
  {
   int tolua_ret = (int)  MD5File(filename,digest);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
  {
   int i;
   for(i=0; i<16;i++)
    tolua_pushfieldstring(tolua_S,2,i+1,(const char*) digest[i]);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MD5File'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: MD5Memory */
#ifndef TOLUA_DISABLE_tolua_owl_MD5Memory00
static int tolua_owl_MD5Memory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_istable(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned char* input = ((unsigned char*)  tolua_tostring(tolua_S,1,0));
  int len = ((int)  tolua_tonumber(tolua_S,2,0));
  unsigned char* digest[16];
  {
#ifndef TOLUA_RELEASE
   if (!tolua_isstringarray(tolua_S,3,16,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<16;i++)
    digest[i] = ((char*)  tolua_tofieldstring(tolua_S,3,i+1,0));
   }
  }
  {
   int tolua_ret = (int)  MD5Memory(input,len,digest);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
  {
   int i;
   for(i=0; i<16;i++)
    tolua_pushfieldstring(tolua_S,3,i+1,(const char*) digest[i]);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MD5Memory'.",&tolua_err);
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
   typedef xint32 tolua_ret = (typedef xint32)  pfnJobProc(parm);
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

/* method: new of class  XThread */
#ifndef TOLUA_DISABLE_tolua_owl_XThread_new00
static int tolua_owl_XThread_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XThread",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XThread* tolua_ret = (XThread*)  Mtolua_new((XThread)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XThread");
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

/* method: new_local of class  XThread */
#ifndef TOLUA_DISABLE_tolua_owl_XThread_new00_local
static int tolua_owl_XThread_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XThread",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XThread* tolua_ret = (XThread*)  Mtolua_new((XThread)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XThread");
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

/* get function: job of class  XThread */
#ifndef TOLUA_DISABLE_tolua_get_XThread_job
static int tolua_get_XThread_job(lua_State* tolua_S)
{
  XThread* self = (XThread*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'job'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->job,"XJob");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: job of class  XThread */
#ifndef TOLUA_DISABLE_tolua_set_XThread_job
static int tolua_set_XThread_job(lua_State* tolua_S)
{
  XThread* self = (XThread*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'job'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"XJob",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->job = *((XJob*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: job_mutex of class  XThread */
#ifndef TOLUA_DISABLE_tolua_get_XThread_job_mutex_ptr
static int tolua_get_XThread_job_mutex_ptr(lua_State* tolua_S)
{
  XThread* self = (XThread*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'job_mutex'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->job_mutex,"XMutex");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: job_mutex of class  XThread */
#ifndef TOLUA_DISABLE_tolua_set_XThread_job_mutex_ptr
static int tolua_set_XThread_job_mutex_ptr(lua_State* tolua_S)
{
  XThread* self = (XThread*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'job_mutex'",NULL);
  if (!tolua_isusertype(tolua_S,2,"XMutex",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->job_mutex = ((XMutex*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
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
  XMutex* tolua_var_3 = ((XMutex*)  tolua_tousertype(tolua_S,1,0));
  {
   XSys::XDeleteMutex(tolua_var_3);
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
  XThread* tolua_var_4 = ((XThread*)  tolua_tousertype(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  XSys::XReleaseThread(tolua_var_4);
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
  XThreadPool* tolua_var_5 = ((XThreadPool*)  tolua_tousertype(tolua_S,1,0));
  {
   XSys::XReleaseThreadPool(tolua_var_5);
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
  tolua_function(tolua_S,"MD5Init",tolua_owl_MD5Init00);
  tolua_function(tolua_S,"MD5Update",tolua_owl_MD5Update00);
  tolua_function(tolua_S,"MD5UpdaterString",tolua_owl_MD5UpdaterString00);
  tolua_function(tolua_S,"MD5FileUpdateFile",tolua_owl_MD5FileUpdateFile00);
  tolua_function(tolua_S,"MD5Final",tolua_owl_MD5Final00);
  tolua_function(tolua_S,"MDString",tolua_owl_MDString00);
  tolua_function(tolua_S,"MD5File",tolua_owl_MD5File00);
  tolua_function(tolua_S,"MD5Memory",tolua_owl_MD5Memory00);
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
   tolua_function(tolua_S,"new",tolua_owl_XThread_new00);
   tolua_function(tolua_S,"new_local",tolua_owl_XThread_new00_local);
   tolua_function(tolua_S,".call",tolua_owl_XThread_new00_local);
   tolua_function(tolua_S,"delete",tolua_owl_XThread_delete00);
   tolua_function(tolua_S,"Suppend",tolua_owl_XThread_Suppend00);
   tolua_function(tolua_S,"Stop",tolua_owl_XThread_Stop00);
   tolua_function(tolua_S,"Resume",tolua_owl_XThread_Resume00);
   tolua_function(tolua_S,"Run",tolua_owl_XThread_Run00);
   tolua_function(tolua_S,"Join",tolua_owl_XThread_Join00);
   tolua_variable(tolua_S,"job",tolua_get_XThread_job,tolua_set_XThread_job);
   tolua_variable(tolua_S,"job_mutex",tolua_get_XThread_job_mutex_ptr,tolua_set_XThread_job_mutex_ptr);
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
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_owl (lua_State* tolua_S) {
 return tolua_owl_open(tolua_S);
};
#endif

