using UnityEngine;
using System.Collections;
using System.Text;
using System.Runtime.InteropServices;
using System.Security;
using System;

public class UnityLua {

	public delegate int LuaStdCallFunction(IntPtr L);

	internal LuaStdCallFunction printFunc;

	public static void pushstdcallfunction(IntPtr L, LuaStdCallFunction func)
	{
		LuaLib.lua_pushstdcallfunction(L, Marshal.GetFunctionPointerForDelegate(func));
	}

	public static int UnityPrint(IntPtr L)
	{
		String info = LuaLib.luaL_checkstring(L, -1);
		Debug.Log("lua output:" + info);
		return 0;
	}

	public void BindLuaFunction(IntPtr L)
	{
		//LuaLib.lua_pushstring(L, "print");
		printFunc = new LuaStdCallFunction(UnityPrint);
		pushstdcallfunction(L, printFunc);
		LuaLib.lua_setglobal(L, "print");
	}
}
