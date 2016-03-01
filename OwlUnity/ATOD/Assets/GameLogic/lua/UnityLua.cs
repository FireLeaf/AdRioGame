using UnityEngine;
using System.Collections;
using System.Text;
using System.Runtime.InteropServices;
using System.Security;
using System;

public class UnityLua {

// 	[AttributeUsage(AttributeTargets.Method)]
// 	public class MonoPInvokeCallbackAttribute : Attribute
// 	{
// 		public MonoPInvokeCallbackAttribute(Type type)
// 		{
// 		}
// 	}

	public delegate int LuaStdCallFunction(IntPtr L);

	internal LuaStdCallFunction printFunc;
	internal LuaStdCallFunction panicFunc;
	internal LuaStdCallFunction loaderFunc;

	public static void pushstdcallfunction(IntPtr L, LuaStdCallFunction func)
	{
		LuaLib.lua_pushstdcallfunction(L, Marshal.GetFunctionPointerForDelegate(func));
	}

	//[MonoPInvokeCallbackAttribute(typeof(LuaStdCallFunction))]
	public static int UnityPrint(IntPtr L)
	{
// 		int n = lua_gettop(L);  /* number of arguments */
// 		int i;
// 		lua_getglobal(L, "tostring");
// 		for (i=1; i<=n; i++) {
// 			const char *s;
// 			lua_pushvalue(L, -1);  /* function to be called */
// 			lua_pushvalue(L, i);   /* value to print */
// 			lua_call(L, 1, 1);
// 			s = lua_tostring(L, -1);  /* get result */
// 			if (s == NULL)
// 				return luaL_error(L, LUA_QL("tostring") " must return a string to "
// 								   LUA_QL("print"));
// 			if (i>1) fputs("\t", stdout);
// 			fputs(s, stdout);
// 			lua_pop(L, 1);  /* pop result */
// 		}
// 		fputs("\n", stdout);

		int n = LuaLib.lua_gettop(L);
		LuaLib.lua_getglobal(L, "tostring");
		for (int i = 0; i < n; i++ ){
			LuaLib.lua_pushvalue(L, -1);
			LuaLib.lua_pushvalue(L, i);
			LuaLib.lua_call(L, 1, 1);
			String s = LuaLib.lua_tostring(L, -1);
			if (s == null || s == ""){
				return LuaLib.luaL_error(L, "\'tostring\' must return a string to \'print\'");
			}
			if (i > 1) Debug.Log("lua output:" + s);
			LuaLib.lua_pop(L, 1);
		}
// 		String info = LuaLib.luaL_checkstring(L, -1);
// 		Debug.Log("lua output:" + info
		return 0;
	}

	//[MonoPInvokeCallbackAttribute(typeof(LuaStdCallFunction))]
	public static int UnityPanic(IntPtr L)
	{
		String info = string.Format("PANIC: unprotected error in call to Lua API ({0})", LuaLib.lua_tostring(L, -1));
		Debug.Log(info);
		return 0;
	}

	//[MonoPInvokeCallback(typeof(LuaStdCallFunction))]
	public static int UnityLoader(IntPtr L)
	{
		String path = LuaLib.luaL_checkstring(L, -1);
		path.Replace('.', '/');
		path += ".lua";
		LuaLib.luaL_loadstring(L, "function p() print(\"hello kitty\") end");
		return 1;
	}

	public void BindLuaFunction(IntPtr L)
	{
		//LuaLib.lua_pushstring(L, "print");
		printFunc = new LuaStdCallFunction(UnityPrint);
		pushstdcallfunction(L, printFunc);
		LuaLib.lua_setglobal(L, "print");

		panicFunc = new LuaStdCallFunction(UnityPanic);
		pushstdcallfunction(L, panicFunc);
		LuaLib.lua_setglobal(L, "panic");

		LuaLib.lua_getglobal(L, "package");
		LuaLib.lua_getfield(L, -1, "loaders");
		int loadersIdx = LuaLib.lua_gettop(L);
		int iLoaderCount = LuaLib.luaL_getn(L, -1);
		for (int i = iLoaderCount + 1; i > 1; i-- )
		{
			LuaLib.lua_rawgeti(L, loadersIdx, i - 1);
			LuaLib.lua_rawseti(L, loadersIdx, i);
		}
		loaderFunc = new LuaStdCallFunction(UnityLoader);
		pushstdcallfunction(L, loaderFunc);
		LuaLib.lua_rawseti(L, loadersIdx, 1);

		LuaLib.lua_settop(L, 0);
	}
}
