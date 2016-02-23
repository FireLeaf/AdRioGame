using UnityEngine;
using UnityEditor;
using System.Collections;
using UnityEditor.Events;
using System;

[CustomEditor(typeof(GridPath))]
public class GridEditor : Editor {

	public void OnEnable(){
	
	}

	public void OnDisable(){

	}

	public override void OnInspectorGUI(){
		if (GUILayout.Button("Save")){
			Debug.Log("");
		}

		//Selection.activeGameObject
		Camera cam = SceneView.lastActiveSceneView.camera;
		if (Event.current.button == 1){
			Ray ray = cam.ScreenPointToRay(Event.current.mousePosition);
			RaycastHit hit;
			if (Physics.Raycast(ray, out hit)){
				//GridPath gp = (GridPath)target;
				//gp.
				GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
				go.transform.position = hit.point;
			}
		}
		Repaint();
	}
}