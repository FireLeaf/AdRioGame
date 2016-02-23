using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.IO;

public class AssetLoader {
	public delegate void OnLoadFinish(Object ob);
	//List<Object> cache_object_;
	Dictionary<string, AssetBundle> cache_bundle_;
	public static string res_path = "D:/Resource/testbundle/";
	public AssetLoader()
	{
		cache_bundle_ = new Dictionary<string, AssetBundle>();
	}

	public void Close(){
		foreach (KeyValuePair<string, AssetBundle> kv in cache_bundle_)
		{
			kv.Value.Unload(false);
		}
		cache_bundle_.Clear();
	}

	byte[] GetFileData(string path)
	{
		FileStream fs = File.OpenRead(res_path + path);
		byte[] data = new byte[fs.Length];
		fs.Read(data, 0, (int)fs.Length);
		fs.Dispose();
		return data;
	}

	AssetBundle GetAssetBundle(string path)
	{
		if (cache_bundle_.ContainsKey(path))
		{
			return cache_bundle_[path];
		}
		
		//FileStream fs = File.OpenRead(res_path + path);
		MemoryStream ms = new MemoryStream(GetFileData(path));
		AssetHead ah = new AssetHead();
		ah.Read(ms);
		for (int i = 0; i < ah.dependencies_.Count; i++ )
		{
			AssetBundle sub = GetAssetBundle(ah.dependencies_[i]);
			if (sub){
				//bundle.Add(sub);
			}
		}
		int len = (int)(ms.Length - ms.Position);
		byte[] bytes = new byte[len];
		if (len != ms.Read(bytes, 0, len))
		{
			Debug.Log("asset error");
		}
		AssetBundle bundle = AssetBundle.CreateFromMemoryImmediate(bytes);
		cache_bundle_[path] = bundle;
		ms.Close();
		ms.Dispose();
		return bundle;
	}

	public Object LoadXGU3DAsset(string path)
	{
		return GetAssetBundle(path).Load("main");
	}
}
