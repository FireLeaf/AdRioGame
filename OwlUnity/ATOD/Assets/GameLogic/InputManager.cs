using UnityEngine;
using System.Collections;
using System;

public class InputManager : MonoBehaviour {

	Camera mainCamera;
	bool isRightDown;
	Vector3 mousePosition;
	// Use this for initialization
	void Start () {
		mainCamera = GameObject.Find ("Main Camera").camera;
		isRightDown = false;
	}
	
	// Update is called once per frame
	void Update () {
		/*
		//left mouse press
		if (!isRightDown && Input.GetMouseButtonDown(1)){
			isRightDown = true;
		}
		else if (isRightDown && Input.GetMouseButtonUp (1)) {
			isRightDown = false;
		}

		if (isRightDown && Input.mousePosition) {

		}
		*/

		//
		if (Input.GetKey(KeyCode.W)) {
			mainCamera.transform.position += mainCamera.transform.forward;
		}

		if (Input.GetKey(KeyCode.S)) {
			mainCamera.transform.position -= mainCamera.transform.forward;
		}

		if (Input.GetKey(KeyCode.A)) {
			mainCamera.transform.position -= mainCamera.transform.right;
		}

		if (Input.GetKey(KeyCode.D)) {
			mainCamera.transform.position += mainCamera.transform.right;
		}

		if (mousePosition == null) {
			mousePosition = Input.mousePosition;
		} else {
			Vector3 deltaPos = mousePosition - Input.mousePosition;
			Debug.Log(deltaPos.x + "," + deltaPos.y + "," + deltaPos.z);
			mainCamera.transform.Rotate(Vector3.up, deltaPos.x);
			mainCamera.transform.Rotate(-Vector3.right, deltaPos.y);
			mousePosition = Input.mousePosition;
		}

		//Physics.r
		/*
		Debug.Log(Input.mousePosition.x + "," + Input.mousePosition.y + "," + Input.mousePosition.z);
		//Screen.lockCursor = true;
		Debug.Log(Input.mousePosition.x + "," + Input.mousePosition.y + "," + Input.mousePosition.z);
		//Screen.lockCursor = false;
		*/
	}
}
