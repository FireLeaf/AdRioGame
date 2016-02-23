using UnityEngine;
using System.Collections;

public class Skill {
	int hp_cost_;
	int mp_cost_;
	
	public int MPCost(){return mp_cost_;}
	public int HPCost(){return hp_cost_;}

	void PreExcute(){}
}
