using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class Pawn : Actor {

	GameObject goTarget;
	NavMeshAgent navAgent;
	// Use this for initialization
	void Start () {
		goTarget = GameObject.Find ("Tower_Base1_2XX");
		navAgent = gameObject.AddComponent<NavMeshAgent>();
		NavMeshHit nmh;
		NavMesh.SamplePosition (goTarget.transform.position, out nmh, 3.0f, -1);
		navAgent.SetDestination (nmh.position);
		navAgent.baseOffset = 0.9f;
		navAgent.speed = 3f;
		navAgent.radius = 0.3f;
		//gameObject.AddComponent<NavMeshObstacle> ();
	}
	
	// Update is called once per frame
	void Update () {
		if (navAgent.enabled) {
			if (navAgent.remainingDistance < 3.0f) {
				animation.Play ("idle", AnimationPlayMode.Mix);
				navAgent.enabled = false;
				//navAgent.Stop ();
			} else {
				animation.Play ("run", AnimationPlayMode.Mix);
			}
		}
	}
}
