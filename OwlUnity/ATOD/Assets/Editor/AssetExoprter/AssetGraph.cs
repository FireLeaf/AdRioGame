using UnityEngine;
using UnityEditor;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

public class AssetGraph {
	public class AssetNode {
		public List<AssetNode> parent_;
		public List<AssetNode> children_;//
		public List<string> children_path_;
		public string path_;//{ get{return path_;}}
		public UnityEngine.Object asset_object_;

		public AssetNode(string path):base(){
			path_ = path;
			children_ = new List<AssetNode>();
			children_path_ = new List<string>();
			parent_ = new List<AssetNode>();
		}

		public bool IsLeaf(){
			return (children_.Count == 0);
		}

		public void AddChild(AssetNode node){
			children_.Add (node);
			children_path_.Add (node.path_);
			if (node.parent_.Find(delegate(AssetNode an) {  
				//return user.UserID == 0;  
				
				return an == node;
			}) == null)
				node.parent_.Add(this);
		}

		public void RemoveChildrenDependices(){
			List<AssetNode> sameDependices = new List<AssetNode>();
			for ( int i = 0; i < children_.Count; i++ )
			{
				AssetNode child = children_[i];
				for (int j = 0; j < child.children_.Count; j++)
				{
					for (int k = 0; k < children_.Count; k++ )
					{
						if (i == k) continue;
						AssetNode otherchild = children_[k];
						AssetNode grandchild = child.children_[j];
						if (otherchild == grandchild)
						{
							sameDependices.Add(grandchild);
						}
					}
				}
			}
			for (int i = 0; i < sameDependices.Count; i++ )
			{
				children_.Remove(sameDependices[i]);
				children_path_.Remove(sameDependices[i].path_);
			}
		}

		public void RemoveFromParent(Dictionary<AssetNode, int> dic_parents){
			for (int i = 0; i < parent_.Count; i++){
				parent_[i].RemoveChild(this);
				if (dic_parents.ContainsKey(parent_[i])){
					dic_parents[parent_[i]]++;
				}else{
					dic_parents[parent_[i]] = 1;
				}
			}
			parent_.Clear ();
		}

		public void RemoveChild(AssetNode node){
			//for (int i = 0; i < children_.Count; i++) {
			//	if (children_[i] == node){
					children_.Remove(node);
			//	}
			//}
		}
	}

	public void CheckGraphNoRing(){
		//Dictionary<AssetNode, bool> node_dict = new Dictionary<AssetNode, bool>();

	}

	public void GetAllLeafNode(out List<AssetNode> node_list){
		node_list = new List<AssetNode>();
		Stack<AssetNode> node_stack = new Stack<AssetNode>();
		node_stack.Push (rootNode);
		AssetNode node;
		while ( node_stack.Count > 0 && (node = node_stack.Pop()) != null ){
			if (node.IsLeaf() ){
				if (node_list.Find(delegate(AssetNode an){  
					//return user.UserID == 0;  
					
					return an == node;
				}) == null)
					node_list.Add(node);
			}
			else{
				for (int i = 0; i < node.children_.Count; i++){
					node_stack.Push(node.children_[i]);
				}
			}
		}
	}

	public void ExportNodeToFile(AssetNode node){
		string temp_path = Application.temporaryCachePath;
		string path = node.path_;
		BuildAssetBundleOptions buildOp = BuildAssetBundleOptions.CollectDependencies | BuildAssetBundleOptions.CompleteAssets | BuildAssetBundleOptions.DeterministicAssetBundle;
		UnityEngine.Object mainAsset = node.asset_object_;//AssetDatabase.LoadMainAssetAtPath (path);
		string dest_path = dir_;
		string asset_final_path = dest_path + path + ".xgu3d";
		string asset_sub_path = Path.GetDirectoryName (path);
		string temp_asset_path = dest_path + path + ".asset";
		Directory.CreateDirectory(dest_path + asset_sub_path);

		//File.Delete(temp_asset_path);
		if (BuildPipeline.BuildAssetBundleExplicitAssetNames(new UnityEngine.Object[] { mainAsset },
																new string[] { "main" }, temp_asset_path, buildOp)
		){

		}
		else
		{
			Debug.Break();
		}
		AssetHead ah = new AssetHead();
		ah.dependencies_ = node.children_path_;

		Directory.CreateDirectory (dest_path + asset_sub_path);
		byte[] asset_bytes = File.ReadAllBytes(temp_asset_path);
		FileStream fs = File.Open(asset_final_path, FileMode.Create, FileAccess.Write);
		ah.Write(fs);
		fs.Write(asset_bytes, 0, asset_bytes.Length);
		fs.Close();
		fs.Dispose();

		File.Delete(temp_asset_path);
	} 

	public void ExportNodeGraph(){
		int iDepLv = 0;
		int iExpCount = 0;
		List<AssetNode> list_leaf;
		GetAllLeafNode(out list_leaf);
		while (true) {
			if (list_leaf.Count <= 0){
				if (iExpCount != node_dict.Count){
					Debug.Log("asset may be have ring");
				}
				break;
			}
			BuildPipeline.PushAssetDependencies();
			iDepLv++;
			Dictionary<AssetNode, int> dic_parents = new Dictionary<AssetNode, int>();
			for (int i = 0; i < list_leaf.Count; i++){
				AssetNode node = list_leaf[i];
				ExportNodeToFile(node);
				if (node.parent_!= null ){
					node.RemoveFromParent(dic_parents);
				}else{
					rootNode = null;
				}
				iExpCount++;
			}
			list_leaf.Clear();
			foreach (KeyValuePair<AssetNode, int> kv in dic_parents){
				if (kv.Key.IsLeaf()){
					list_leaf.Add(kv.Key);
				}
			}
			dic_parents.Clear();
		}
		for (int i = 0; i < iDepLv; i++){
			BuildPipeline.PopAssetDependencies();
		}
	}

	public void BuildNodeGraph(string path, AssetNode parent){
		AssetNode newNode;
		if (node_dict.TryGetValue (path, out newNode)) {
			parent.AddChild(newNode);
			return;
		}

		string curpath = path;

		if (parent != null) {
			newNode = new AssetNode (curpath);
			parent.AddChild(newNode);
		} else {
			rootNode = new AssetNode(curpath);
			newNode = rootNode;
		}
		node_dict [path] = newNode;
		newNode.asset_object_ = AssetDatabase.LoadMainAssetAtPath(path);
		if (newNode.asset_object_ == null){
			
			return;
		}

		string[] sub = AssetDatabase.GetDependencies (new string[]{curpath});
		for (int i = 0; i < sub.Length; i++){
			if (sub[i] == curpath)
			{
				continue;
			}
			BuildNodeGraph(sub[i], newNode);
		}
	}

	public void SimplifyDependencies (){//精简依赖
		Stack<AssetNode> node_stack = new Stack<AssetNode>();
		node_stack.Push(rootNode);
		AssetNode node;
		while (node_stack.Count > 0 && (node = node_stack.Pop()) != null)
		{
			node.RemoveChildrenDependices();
			for (int i = 0; i < node.children_.Count; i++)
			{
				node_stack.Push(node.children_[i]);
			}
		}
	}

	public void ExportAssetByPath(string path, string dir){
		dir_ = dir;
		BuildNodeGraph (path, null);
		SimplifyDependencies();
		ExportNodeGraph ();
	}

	public AssetGraph(){
		node_dict = new Dictionary<string, AssetNode>();
	}

	public AssetNode rootNode;
	public Dictionary<string, AssetNode> node_dict;
	private string dir_;
}
