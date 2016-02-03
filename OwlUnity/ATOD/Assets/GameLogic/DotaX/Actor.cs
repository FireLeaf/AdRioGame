using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class Actor : MonoBehaviour {

	int hp_;
	int mp_;
	int armor_;
	int magic_resist_;

	int strength_;
	int intelligence_;
	int agility_;



	List<Buf> bufs_;
	IvtrItem[] items_ = new IvtrItem[6];

	void HPChange(float hp){}
	void MPChange(float mp){}


	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
