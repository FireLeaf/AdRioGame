using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.IO;

public class Dota2Player : MonoBehaviour {
	public Camera mainCamera;
	NavMeshAgent navAgent;
	public Texture2D texture;
	GameObject goTree;
	List<GameObject> dynmicObstacle;
	GameObject spawnCache;
	GameObject goBundle;
	void Start () {
		OwlGame.og_initModule ("D:/Hello/", "D:/OK/");
		navAgent = GetComponent<NavMeshAgent> ();
		mainCamera = GameObject.Find ("Main Camera").camera;
		//TextureFormat
		//texture = new Texture2D ();
		//texture.
		Transform bone = transform.FindChild ("Bip001 L Clavicle");
		//GameObject GameObject.CreatePrimitive (PrimitiveType.Cube);
		//dynmicObstacle.Add (GameObject.Find(""));
		goTree = (GameObject) Resources.Load("Trees/BigTree");
		goTree.transform.localScale = new Vector3(0.12f, 0.37f, 0.12f);
		/*NavMeshObstacle nmo = goTree.AddComponent<NavMeshObstacle>();
		nmo.carving = true;*/
		spawnCache =Resources.LoadAssetAtPath<GameObject>("Assets/Standard Assets/Character Controllers/Sources/PrototypeCharacter/Constructor.FBX");
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetMouseButtonDown (0)) {
			Ray ray = mainCamera.ScreenPointToRay(Input.mousePosition);
			RaycastHit hit;
			if (Physics.Raycast(ray, out hit)){
				//if the raycast is terrain
				/*if (!hit.collider.name.Equals("Terrain")){
					return;
				}*/
				Vector3 pos = hit.point;
				//transform.LookAt(new Vector3(pos.x, transform.position.y, pos.z) );
				navAgent.SetDestination(pos);
			}
		}
		
		if (Input.GetMouseButtonDown (1)) {
			/*GameObject go = GameObject.Find("Cylinder");
			if (go){
				GameObject.Destroy(go);
			}*/
			GameObject newSpawn = Instantiate(spawnCache) as GameObject;
			newSpawn.transform.position = new Vector3(37.95441f - 11.14441f, 5.45632f, 103.1935f + 9.306473f);
			newSpawn.AddComponent<Pawn>();
		}
		
		/*if (Input.GetMouseButtonDown (2)) {
			Ray ray = mainCamera.ScreenPointToRay(Input.mousePosition);
			RaycastHit hit;
			if (Physics.Raycast(ray, out hit)){
				GameObject dynamicObstacle = GameObject.Find("DynamicObstacle");
				GameObject go = Instantiate(goTree) as GameObject;
				Vector3 pos = hit.point;
				go.transform.position = new Vector3(pos.x, pos.y, pos.z);
				go.transform.parent = dynamicObstacle.transform;
			}
		}*/
		
		if (navAgent.remainingDistance == 0) {
			animation.Play("idle", AnimationPlayMode.Mix);
		} else {
			animation.Play("run", AnimationPlayMode.Mix);
		}
		
		Vector3 vPlayer = transform.position;
		mainCamera.transform.forward = new Vector3(1.0f, -2.0f, -0.2f);//new Vector3 (0.0f, -6.0f, 9.0f);
		float dist = 20.0f;
		Vector3 fd = mainCamera.transform.forward;
		mainCamera.transform.position = new Vector3(vPlayer.x - dist * fd.x, vPlayer.y  - dist * fd.y, vPlayer.z - dist * fd.z);
		mainCamera.transform.LookAt (vPlayer);
		//mainCamera.transform.right = Vector3.Cross (Vector3.up, mainCamera.transform.forward);
		//mainCamera.transform.up = Vector3.up;
	}
}
