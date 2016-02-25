using UnityEngine;
using System.Collections;
using System.Text;
using System.Runtime.InteropServices;
using System.Security;
using System;

public partial class LuaLib {


    /* extra error code for `luaL_load' */
    public static readonly String LUA_FILEHANDLE = "FILE*";
    public static readonly String LUA_COLIBNAME = "coroutine";
    public static readonly String LUA_TABLIBNAME = "table";
    public static readonly String LUA_IOLIBNAME = "io";
    public static readonly String LUA_OSLIBNAME = "os";
    public static readonly String LUA_STRLIBNAME = "string";
    public static readonly String LUA_MATHLIBNAME = "math";
    public static readonly String LUA_DBLIBNAME = "debug";
    public static readonly String LUA_LOADLIBNAME = "package";

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaopen_base(IntPtr L);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaopen_table(IntPtr L);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaopen_io(IntPtr L);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaopen_os(IntPtr L);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaopen_string(IntPtr L);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaopen_math(IntPtr L);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaopen_debug(IntPtr L);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaopen_package(IntPtr L);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void luaL_openlibs(IntPtr L);
}
