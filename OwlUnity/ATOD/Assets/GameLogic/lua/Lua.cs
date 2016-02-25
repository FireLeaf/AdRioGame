using UnityEngine;
using System.Collections;
using System.Text;
using System.Runtime.InteropServices;
using System.Security;
using System;

public partial class LuaLib {

	#if UNITY_IPHONE
	const string OwlGameModule = "__Internal";
#else
	const string OwlGameModule = "OwlGame";
	#endif

    //lua.h
	public static readonly string LUA_VERSION = "Lua 5.1";
	public static readonly string LUA_RELEASE = "Lua 5.1.5";
	public static readonly int LUA_VERSION_NUM = 501;
	public static readonly string LUA_COPYRIGHT = "Copyright (C) 1994-2012 Lua.org, PUC-Rio";
	public static readonly string LUA_AUTHORS = "R. Ierusalimschy, L. H. de Figueiredo & W. Celes";

	public static readonly string LUA_SIGNATURE = "\033Lua";

	public static readonly int LUA_MULTRET = (-1);

	public static readonly int LUA_REGISTRYINDEX = (-10000);
	public static readonly int LUA_ENVIRONINDEX = (-10001);
	public static readonly int LUA_GLOBALSINDEX = (-10002);
    //public static readonly int lua_upvalueindex(i)	(LUA_GLOBALSINDEX-(i))

    public static int lua_upvalueindex(int i){
        return (LUA_GLOBALSINDEX-(i));
    }
/* thread status; 0 is OK */
    public static readonly int LUA_YIELD =	1;
    public static readonly int LUA_ERRRUN = 2;
    public static readonly int LUA_ERRSYNTAX = 3;
    public static readonly int LUA_ERRMEM = 4;
    public static readonly int LUA_ERRERR = 5;

    /*
** basic types
*/
    public static readonly int LUA_TNONE = (-1);

    public static readonly int LUA_TNIL = 0;
    public static readonly int LUA_TBOOLEAN = 1;
    public static readonly int LUA_TLIGHTUSERDATA = 2;
    public static readonly int LUA_TNUMBER = 3;
    public static readonly int LUA_TSTRING = 4;
    public static readonly int LUA_TTABLE = 5;
    public static readonly int LUA_TFUNCTION = 6;
    public static readonly int LUA_TUSERDATA = 7;
    public static readonly int LUA_TTHREAD	= 8;



/* minimum Lua stack available to a C function */
    public static readonly int LUA_MINSTACK = 20;


    /*
** state manipulation
*/
	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern IntPtr luaL_newstate (IntPtr f, IntPtr ud);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_close (IntPtr L);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern IntPtr lua_newthread (IntPtr L);
    /*
** basic stack manipulation
*/
	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_gettop (IntPtr L);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_settop (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushvalue (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_remove (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_insert (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_replace (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_checkstack (IntPtr L, int sz);


    /*
    ** access functions (stack -> C)
    */

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_isnumber (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_isstring (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_iscfunction (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_isuserdata (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_type (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern string lua_typename (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_equal (IntPtr L, int idx1, int idx2);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_rawequal (IntPtr L, int idx1, int idx2);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_lessthan (IntPtr L, int idx1, int idx2);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern double lua_tonumber (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_tointeger (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern int lua_toboolean (IntPtr L, int idx);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern uint lua_objlen(IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern IntPtr lua_tocfunction (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern IntPtr lua_touserdata (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern IntPtr lua_tothread (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern IntPtr lua_topointer (IntPtr L, int idx);

    /*
** push functions (C -> stack)
*/

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushnil (IntPtr L);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushnumber (IntPtr L, double n);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushinteger (IntPtr L, int n);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushlstring(IntPtr L, byte[] s, int n );

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushstring(IntPtr L, String s);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushstdcallfunction(IntPtr L, IntPtr func);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_pushboolean(IntPtr L, int b);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_pushlightuserdata(IntPtr L, IntPtr p);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_pushthread(IntPtr L);

    /*
** get functions (Lua -> stack)
*/

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_gettable(IntPtr L, int idx);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_getfield(IntPtr L, int idx, String key);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_rawget(IntPtr L, int idx);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_rawgeti(IntPtr L, int idx, int n);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_createtable(IntPtr L, int narr, int nrec);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_newuserdata(IntPtr L, uint sz);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_getmetatable(IntPtr L, int objindex);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_getfenv(IntPtr L, int idx);

    /*
** set functions (stack -> Lua)
*/
    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_settable(IntPtr L, int idx);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_setfield(IntPtr L, int idx, String key);
    
    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_rawset(IntPtr L, int idx);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_rawseti(IntPtr L, int idx, int n);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_setmetatable(IntPtr L, int objindex);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_setfenv(IntPtr L, int idx);

    /*
** `load' and `call' functions (load and run Lua code)
*/
    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_call(IntPtr L, int nargs, int nresults);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int lua_pcall(IntPtr L, int nargs, int nresults, int errFunc);
/*
** coroutine functions
*/
    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int lua_yield(IntPtr L, int nresults);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int lua_resume(IntPtr L, int narg);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int lua_status(IntPtr L);

    /*
** garbage-collection function and options
*/
    public static readonly int LUA_GCSTOP = 0;
    public static readonly int LUA_GCRESTART = 1;
    public static readonly int LUA_GCCOLLECT = 2;
    public static readonly int LUA_GCCOUNT = 3;
    public static readonly int LUA_GCCOUNTB = 4;
    public static readonly int LUA_GCSTEP = 5;
    public static readonly int LUA_GCSETPAUSE = 6;
    public static readonly int LUA_GCSETSTEPMUL = 7;

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int lua_gc(IntPtr L, int what, int data);

    /*
** miscellaneous functions
*/
    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int lua_error(IntPtr L);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int lua_next(IntPtr L, int idx);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int lua_concat(IntPtr L, int n);

    /* 
** ===============================================================
** some useful macros
** ===============================================================
*/
    public static void lua_pop(IntPtr L, int n) { lua_settop(L, -(n)-1); }
    public static void lua_newtable(IntPtr L) { lua_createtable(L, 0, 0); }
    public static void lua_strlen(IntPtr L, int i) { lua_objlen(L, i); }
    public static bool lua_isfunction(IntPtr L, int n) { return lua_type(L, n) == LUA_TFUNCTION;}
    public static bool lua_istable(IntPtr L, int n) { return lua_type(L, n) == LUA_TTABLE; }
    public static bool lua_islightuserdata(IntPtr L, int n) { return lua_type(L, n) == LUA_TLIGHTUSERDATA; }
    public static bool lua_isnil(IntPtr L, int n) { return lua_type(L, n) == LUA_TNIL; }
    public static bool lua_isboolean(IntPtr L, int n) { return lua_type(L, n) == LUA_TBOOLEAN; }
    public static bool lua_isthread(IntPtr L, int n) { return lua_type(L, n) == LUA_TTHREAD; }
    public static bool lua_isnone(IntPtr L, int n) { return lua_type(L, n) == LUA_TNONE; }
    public static bool lua_isnoneornil(IntPtr L, int n) { return lua_type(L, n) <= 0; }

    public static void lua_setglobal(IntPtr L, String s) { lua_setfield(L, LUA_GLOBALSINDEX, s); }
    public static void lua_getglobal(IntPtr L, String s) { lua_getfield(L, LUA_GLOBALSINDEX, s); }

    //public static void lua_tostring(IntPtr L, int i) { lua_tolstring};

    public static IntPtr lua_open() { return luaL_newstate(); }

    public static void lua_getregistry(IntPtr L) { lua_pushvalue(L, LUA_REGISTRYINDEX); }
    public static int lua_getgccount(IntPtr L) { return lua_gc(L, LUA_GCCOLLECT, 0); }

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void lua_setlevel(IntPtr from, IntPtr to);

    /*
** Event codes
*/
    public static readonly int LUA_HOOKCALL = 0;
    public static readonly int LUA_HOOKRET = 1;
    public static readonly int LUA_HOOKLINE = 2;
    public static readonly int LUA_HOOKCOUNT = 3;
    public static readonly int LUA_HOOKTAILRET = 4;


/*
** Event masks
*/
    public static readonly int LUA_MASKCALL = (1 << LUA_HOOKCALL);
    public static readonly int LUA_MASKRET	= (1 << LUA_HOOKRET);
    public static readonly int LUA_MASKLINE = (1 << LUA_HOOKLINE);
    public static readonly int LUA_MASKCOUNT = (1 << LUA_HOOKCOUNT);

    //[StructLayout(LayoutKind.Sequential)]
}
