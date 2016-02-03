using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class Tower : MonoBehaviour {

	GameObject goNavPlayer;
	float attackCooling;
	List<GameObject> attackBullets = new List<GameObject>();
	GameObject bulletCache;
	GameObject bullets;
	// Use this for initialization
	void Start () {
		return;
		bulletCache = Resources.LoadAssetAtPath("Assets/MOBA and Tower Defense/Prefabs_Skill/TowerAttack.prefab", typeof(GameObject)) as GameObject;
		goNavPlayer = GameObject.Find ("Constructor").transform.Find("construction_worker").gameObject;
		attackCooling = 0;
		bullets = new GameObject ("Bullets");

		gameObject.AddComponent<NavMeshObstacle>();
	}

	void Attack(GameObject go){
		if (attackCooling <= 0) {
			GameObject newBullet = Instantiate(bulletCache) as GameObject;
			for (int i = 0; i < newBullet.transform.childCount; i++){
				newBullet.transform.GetChild(i).gameObject.SetActive(true);
			}
			newBullet.transform.parent = bullets.transform;
			newBullet.transform.position = transform.position;
			attackBullets.Add(newBullet);
			attackCooling = 1.0f;
		}
	}

	void UpdateBullet() {
		Vector3 playerPos = goNavPlayer.transform.position;// - new Vector3(0.0f, 4.0f, 0.0f);
		GameObject[] objs = attackBullets.ToArray();
		attackBullets.Clear ();
		for (int i = 0; i < objs.Length; i++) {
			GameObject go = objs[i];
			Vector3 bulletPos = go.transform.position;
			Vector3 v = playerPos - bulletPos;
			float len = v.magnitude;
			v.Normalize();

			Vector3 deltaPos = v * (5f * Time.deltaTime);
			if (deltaPos.magnitude > len){
				deltaPos = playerPos - bulletPos;
			}

			go.transform.position += deltaPos;

			if ( (playerPos - bulletPos).magnitude < 0.03f ){
				DestroyObject(go);
			} else{
				attackBullets.Add(go);
			}
		}
	}

	// Update is called once per frame
	void Update () {
		return;
		if (attackCooling > 0){
			attackCooling -= Time.deltaTime;
		}

		UpdateBullet();

		Vector3 pos = goNavPlayer.transform.position;
		if ( (pos - transform.position).magnitude < 8.0f ){
			Attack(goNavPlayer);
		}
	}
}
