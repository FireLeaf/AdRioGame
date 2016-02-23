using UnityEngine;
using System;
using System.Collections;
using System.Security;
using System.Runtime.InteropServices;
using System.Text;

public class OwlGame {

#if UNITY_IPHONE
	const string OwlGameModule = "__Internal";
#else
	const string OwlGameModule = "OwlGame";
#endif
	
	[DllImport(OwlGameModule)]
	public static extern bool  og_initModule (string szWriteablePath, string szBundlePath) ;

	[DllImport(OwlGameModule)]
	public static extern void og_releaseBuffer(IntPtr buf);

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
