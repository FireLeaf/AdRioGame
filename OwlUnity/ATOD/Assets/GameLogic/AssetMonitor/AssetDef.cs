using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.IO;

public class AssetHead {

	public List<string> dependencies_;
	public AssetHead(){
		dependencies_ = new List<string>();
	}
	
	public void Read(Stream input) {
		BinaryReader br = new BinaryReader(input);
		int depend_count = br.ReadInt32();
		for (int i = 0; i < depend_count; i++ ) {
			dependencies_.Add(br.ReadString());
		}
	}

	public void Write(Stream output) {
		BinaryWriter bw = new BinaryWriter(output);
		bw.Write(dependencies_.Count);
		for (int i = 0; i < dependencies_.Count; i++ ){
			bw.Write(dependencies_[i] + ".xgu3d");
		}
	}
}
