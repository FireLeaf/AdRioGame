using UnityEngine;
using System.Collections;
using System.IO;

public class test : MonoBehaviour {

	public GameObject cube;
	private float angle;
	RenderTexture texture;
	Renderer render;
	Camera mainCamera;
	GameObject inputManager;
	GameObject goBundle;
	// Use this for initialization
	void Start () {
		return;
		/*string path = "D:/Resource/testbundle/Assets/Material/test.prefab.xgu3d";
		FileStream myStream = new FileStream(path, FileMode.Open, FileAccess.Read);//("D:/Resource/testbundle/Assets/Standard Assets/Character Controllers/Sources/PrototypeCharacter/Constructor.FBX.xgu3d", FileMode.Open, FileAccess.Read);
		BinaryReader myReader = new BinaryReader(myStream);
		byte[] bts = myReader.ReadBytes((int)myStream.Length);
		AssetBundle ab = AssetBundle.CreateFromMemoryImmediate(bts);
		goBundle = Instantiate(ab.Load("main"))  as GameObject;
		ab.Unload (false);*/
		AssetLoader al = new AssetLoader();
		goBundle = Instantiate(al.LoadXGU3DAsset("Assets/Material/test2.prefab.xgu3d")) as GameObject;
		al.Close();
		/*cube = gameObject.transform.Find ("Cube").gameObject;
		angle = 0.0f;
		//cube.renderer.ma
		render = cube.GetComponent<Renderer> ();
		StartCoroutine (Do ());
		mainCamera = GameObject.Find ("Main Camera").camera;
		inputManager = new GameObject("InputManager");
		inputManager.AddComponent<InputManager>();
		//inputManager.transform.parent = gameObject.transform;
		*/
	}

	IEnumerator Do(){
		Debug.Log ("hello 1");
		yield return null;
		Debug.Log ("kitty");
		foreach(var i in Something())
			yield return i;
		Debug.Log ("kitty1");
		yield break;
	}

	IEnumerable Something(){
		Debug.Log ("hello 2");
		yield return null;
		Debug.Log ("kitty 2");
		yield break;
		Debug.Log ("kitty 4");
		yield break;
	}

	// Update is called once per frame
	void Update () {
		//Debug.Log ("delta " + Time.deltaTime + ";fix " + Time.fixedDeltaTime);
		//;
		/*angle += Time.deltaTime * 10;
		cube.transform.RotateAround(gameObject.transform.position, new Vector3(0.0f, 1.0f, 0.0f), angle);
		render.material.color = new Color(0xff, 0x00, 0xff);*/
	}

	// 
	void OnGUI(){
		if (GUILayout.Button ("Hello World")) {
			Debug.Log("press btn");
		}
	}
}
