using UnityEngine;
using System;
using System.Collections;
using System.IO;
using System.Runtime.InteropServices;

public class FileBridge {

#if UNITY_IPHONE
	const string OwlGameModule = "__Internal";
#else
	const string OwlGameModule = "OwlGame";
#endif

	[DllImport(OwlGameModule)]
	public static extern IntPtr og_getFileData(string path, IntPtr size);

	public static byte[] GetSpeFileData(string path)
	{
		FileStream fs = File.OpenRead(path);
		byte[] data = new byte[fs.Length];
		fs.Read(data, 0, (int)fs.Length);
		fs.Dispose();
		return data;
	}

	public static byte[] getFileData(string path)
	{
		IntPtr size = Marshal.AllocHGlobal(sizeof(int));
		IntPtr dataPtr = og_getFileData(path, size);
		if (dataPtr == null){
			int bufLen = 0;
			Marshal.PtrToStructure(size, bufLen);
			byte[] data = new byte[bufLen];
			Marshal.Copy(dataPtr, data, 0, bufLen);
			OwlGame.og_releaseBuffer(dataPtr);
			return data;
		}
		Marshal.Release(size);
		return GetSpeFileData(path);
	}
}
