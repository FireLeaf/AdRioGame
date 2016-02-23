using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
using System.IO;

static public class AssetExport {

	/*[MenuItem("AssetExporter/", false, 12)]
	static void Breaker(){

	}*/

	static Dictionary<string, int> map_exported = new Dictionary<string, int>();
	static void exportAAsset(Object ass){

	}

	static void exportAssetFromPath(string path){
		if (map_exported.ContainsKey(path)){
			return;
		}
		Object mainAsset = AssetDatabase.LoadMainAssetAtPath (path);
		if (!mainAsset) {
			return;
		}
		BuildPipeline.PushAssetDependencies ();
		string[] depth = AssetDatabase.GetDependencies (new string[]{path});
		for ( int i = 0; i < depth.Length; i++){
			if (depth[i] == path){
				continue;
			}
			exportAssetFromPath(depth[i]);
		}
		BuildAssetBundleOptions buildOp = BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.CompleteAssets | BuildAssetBundleOptions.DeterministicAssetBundle;
		string dest_path = "D:\\Resource\\testbundle\\";
		string asset_sub_path = Path.GetDirectoryName (path);
		Directory.CreateDirectory (dest_path + asset_sub_path);
		BuildPipeline.BuildAssetBundleExplicitAssetNames (new Object[]{mainAsset}, new string[]{"main"}, dest_path + path + ".xgu3d", buildOp);
		map_exported [path] = 1;
		BuildPipeline.PopAssetDependencies ();
	}

	static void exportu3dbundle(string path){
		BuildAssetBundleOptions buildOp = BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.CompleteAssets | BuildAssetBundleOptions.DeterministicAssetBundle;
		Object mainAsset = AssetDatabase.LoadMainAssetAtPath (path);
		string dest_path = "D:\\Resource\\testbundle\\";
		string asset_sub_path = Path.GetDirectoryName (path);
		Directory.CreateDirectory (dest_path + asset_sub_path);
		BuildPipeline.BuildAssetBundleExplicitAssetNames (new Object[]{mainAsset}, new string[]{"main"}, dest_path + path + ".xgu3d", buildOp);
	}

	static void manually_export(){
		BuildPipeline.PushAssetDependencies ();
		exportu3dbundle ("Assets/Material/terrain1.jpg");
		BuildPipeline.PushAssetDependencies ();
			exportu3dbundle ("Assets/Material/NewShader.shader");
				BuildPipeline.PushAssetDependencies ();
					exportu3dbundle ("Assets/Material/New Material.mat");
					BuildPipeline.PushAssetDependencies ();
						exportu3dbundle ("Assets/Material/test.prefab");
					BuildPipeline.PopAssetDependencies ();
				BuildPipeline.PopAssetDependencies ();
			BuildPipeline.PopAssetDependencies ();
		BuildPipeline.PopAssetDependencies ();
	}

	[MenuItem("AssetExporter/exportBundle", false)]
	static void exportAssetPath(){
		/*manually_export ();
		return;*/
		map_exported.Clear ();
		Object[] selection = Selection.GetFiltered (typeof(Object), SelectionMode.DeepAssets);
		foreach (Object sel in selection){
			//exportAssetFromPath(AssetDatabase.GetAssetPath(sel));
			new AssetGraph().ExportAssetByPath(AssetDatabase.GetAssetPath(sel), "D:\\Resource\\testbundle\\");
		}
	}

	[MenuItem("AssetExporter/exportAsset", false)]
	static void exportAsset(){
		//EditorUserBuildSettings.activeBuildTarget;
		Object[] selection = Selection.GetFiltered (typeof(Object), SelectionMode.DeepAssets);
		foreach (Object sel in selection){
			Object[] collection = EditorUtility.CollectDependencies(new Object[]{sel});
			ExportOne(sel);
		}
	}

	public static Dictionary<string, int>  mapDepth = new Dictionary<string, int>();
	static void ExportOne(Object ob){
		string assetPath = AssetDatabase.GetAssetPath (ob);
		string[] depth = AssetDatabase.GetDependencies(new string[]{assetPath});
		for(int i = 0; i < depth.Length; i++){
			if (assetPath.Equals(depth[i])){
				continue;
			}
			Object sub = AssetDatabase.LoadMainAssetAtPath(depth[i]);
			ExportOne(sub);
		}
		//AssetBundle.CreateFromMemoryImmediate().Load()
	}

	[MenuItem("AssetExporter/exportAsset", true)]
	static bool CanEnableExportAsset(){
		return true;
	}

	[MenuItem("Assets/Hello")]
	static void HelloAsset(){

	}
}
