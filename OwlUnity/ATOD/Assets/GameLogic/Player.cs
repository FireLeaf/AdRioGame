using UnityEngine;
using System.Collections;


public class Player : MonoBehaviour {

	GameObject goPlayer;
	Camera mainCamera;
	// Use this for initialization
	void Start () {
		goPlayer = gameObject.transform.Find ("Player").gameObject;
		mainCamera = GameObject.Find ("Main Camera").camera;
	}
	
	// Update is called once per frame
	void Update () {
		Vector3 vPlayer = goPlayer.transform.position;
		if (Input.GetKey (KeyCode.W))
			vPlayer.z += Time.deltaTime * 20.0f;
		if (Input.GetKey (KeyCode.S))
			vPlayer.z -= Time.deltaTime * 20.0f;
		if (Input.GetKey (KeyCode.A))
			vPlayer.x -= Time.deltaTime * 20.0f;
		if (Input.GetKey (KeyCode.D))
			vPlayer.x += Time.deltaTime * 20.0f;
		Vector3 vFixPos = vPlayer + new Vector3 (0.0f, 0.0f, 0.0f);
		Ray ray = new Ray (vFixPos, -Vector3.up);
		RaycastHit hit = new RaycastHit();
		if (Physics.Raycast (ray, out hit)) {
			vPlayer += new Vector3(0.0f, 1.0f, 0.0f) - Vector3.up * hit.distance;
			goPlayer.transform.position = vPlayer;
		}

		mainCamera.transform.position = new Vector3(vPlayer.x, vPlayer.y + 10.0f, vPlayer.z - 30.0f);
		mainCamera.transform.forward = new Vector3 (0.0f, -1.0f, 1.0f);
		//mainCamera.transform.right = Vector3.Cross (Vector3.up, mainCamera.transform.forward);
		mainCamera.transform.up = Vector3.up;//Vector3.Cross(mainCamera.transform.right, mainCamera.transform.forward);//Vector3.up;
	}
}
