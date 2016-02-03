using UnityEngine;
using System.Collections;

public class Buf {


	float life_cycle_;//
	bool is_attack_effect_;//
	bool is_orb;//

	public bool IsGhost() {return false;}
	public bool IsImmunity() {return false;}
	public float GetHPRecoverSpeed(){return 0.0f;}
	public float GetMPRecoverSpeed(){return 0.0f;}

	public float GetHPAdd(){return 0.0f;}
	public float GetMPAdd(){return 0.0f;}
	public float GetArmorAdd(){return 0.0f;}

	public float GetSpeedAdd(){return 0.0f;}

	public bool IsLive(){return life_cycle_ > 0.0f;}

	public Buf(){
		life_cycle_ = 0.0f;
	}

	public void EnterBuf(){}
	public void LeaveBuf(){}

	public void Update(){
		if (IsLive()){
			life_cycle_ -= Time.deltaTime;
		}
	}
}
