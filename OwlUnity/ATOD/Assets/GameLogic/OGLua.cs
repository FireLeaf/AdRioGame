using UnityEngine;
using System.Collections;
using System.Text;
using System.Runtime.InteropServices;
using System.Security;
using System;

public class OGLua {

	#if UNITY_IPHONE
	const string OwlGameModule = "__Internal";
	#else
	const string OwlGameModule = "OwlGame";
	#endif

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern IntPtr luaL_newstate ();

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_close (IntPtr L);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern IntPtr lua_newthread (IntPtr L);

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
	public static extern IntPtr lua_tocfunction (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern IntPtr lua_touserdata (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern IntPtr lua_tothread (IntPtr L, int idx);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern IntPtr lua_topointer (IntPtr L, int idx);



	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushnil (IntPtr L);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushnumber (IntPtr L, double n);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushinteger (IntPtr L, int n);

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushlstring(IntPtr L, byte[] s, int n );

	[DllImport(OwlGameModule, CallingConvention = CallingConvention.Cdecl)]
	public static extern void lua_pushstring ();

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
