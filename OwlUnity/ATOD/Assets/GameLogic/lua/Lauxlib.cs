using UnityEngine;
using System.Collections;
using System.Text;
using System.Runtime.InteropServices;
using System.Security;
using System;

public partial class LuaLib {

    public static int luaL_getn(IntPtr L, int i) { return ((int)lua_objlen(L, i));}
    public static void luaL_setn(IntPtr L, int i, int j) {}

    /* extra error code for `luaL_load' */
    public static readonly int LUA_ERRFILE = (LUA_ERRERR + 1);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaL_getmetafield(IntPtr L, int obj, String e);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaL_callmeta(IntPtr L, int obj, String e);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaL_typerror(IntPtr L, int narg, String tname);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaL_argerror(IntPtr L, int numarg, String extramsg);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern String luaL_checklstring(IntPtr L, int numArg, uint l);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern String luaL_optlstring(IntPtr L, int numArg, String def, uint l);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern double luaL_checknumber(IntPtr L, int numArg);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern double luaL_optnumber(IntPtr L, int nArg, double def);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern uint luaL_checkinteger(IntPtr L, int numArg);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern uint luaL_optinteger(IntPtr L, int nArg, uint def);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void luaL_checkstack(IntPtr L, int sz, String msg);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void luaL_checktype(IntPtr L, int narg, int t);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void luaL_checkany(IntPtr L, int narg);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void luaL_where(IntPtr L, int lvl);

    //[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    //public static extern void luaL_error(IntPtr L, );

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaL_ref(IntPtr L, int t);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern void luaL_unref(IntPtr L, int t, int rf);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaL_loadfile(IntPtr L, String filename);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaL_loadbuffer(IntPtr L, byte[] buff, uint sz, String name);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaL_loadbinbuffer(IntPtr L, IntPtr buff, uint sz, String name);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern int luaL_loadstring(IntPtr L, String s);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr luaL_newstate();

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern String luaL_gsub(IntPtr L, String s, String p, String r);

    [DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
    public static extern String luaL_findtable(IntPtr L, int idx, String fname, int szhint);

    /*
** ===============================================================
** some useful macros
** ===============================================================
*/
    public static void luaL_argcheck(IntPtr L, bool cond, int numarg, String extramsg) { if (!cond)  luaL_argerror(L, numarg, extramsg);}
    public static String luaL_checkstring(IntPtr L, int n) { return luaL_checklstring(L, n, 0); }
    public static String luaL_optstring(IntPtr L, int n, String def) { return luaL_optlstring(L, n, def, 0); }
    public static int luaL_checkint(IntPtr L, int n) { return (int)luaL_checkinteger(L, n); }
    public static int luaL_optint(IntPtr L, int n, int d) { return (int)luaL_optinteger(L, n, (uint)d); }
    public static long luaL_checklong(IntPtr L, int n) { return (long)luaL_checkinteger(L, n); }
    public static long luaL_optlong(IntPtr L, int n, int d) { return (long)luaL_optinteger(L, n, (uint)d); }

    public static String luaL_typename(IntPtr L, int i) { return lua_typename(L, lua_type(L, i)); }
    public static bool luaL_dofile(IntPtr L, String funcname) { return (0 != luaL_loadfile(L, funcname)) || (0 != lua_pcall(L, 0, LUA_MULTRET, 0)); }
    public static bool luaL_dostring(IntPtr L, String s) { return (0 != luaL_loadstring(L, s)) || (0 != lua_pcall(L, 0, LUA_MULTRET, 0)); }
    public static void luaL_getmemtatable(IntPtr L, String n) { lua_getfield(L, LUA_REGISTRYINDEX, n); }
    
    /* pre-defined references */
    public static readonly int LUA_NOREF = (-2);
    public static readonly int LUA_REFNIL = (-1);

    public static int lua_ref(IntPtr L, bool lck)
    { 
        if (lck)
            return luaL_ref(L, LUA_REGISTRYINDEX);
        else 
        {
            lua_pushstring(L, "unlocked references are obsolete");
            lua_error(L);
            return 0;
        }
    }

    public static void lua_unref(IntPtr L, int rf) { luaL_unref(L, LUA_REGISTRYINDEX, rf); }
    public static void lua_getref(IntPtr L, int rf) { lua_rawgeti(L, LUA_REGISTRYINDEX, rf); }
    
}
