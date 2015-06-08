using UnityEngine;
using System.Collections;

public class EnemyGunGo : MonoBehaviour
{

	public GameObject EnemyBulletGo;
	public float timer = 3;
	private float timerFlag;
	// Use this for initialization
	void Start () 
	{
		timerFlag = timer;
		Invoke("FireEnemyBullet", 1f);

	}
	
	// Update is called once per frame
	void Update ()
	{
		if(timer > 0)
		{
			timer -= Time.deltaTime;
		}
		if (timer < 0)
		{
			Invoke("FireEnemyBullet", 1f);
			timer = timerFlag;
		}
	}

	void FireEnemyBullet()
	{
		GameObject EnemyBoss = GameObject.Find("player");
		if (EnemyBoss != null)
		{
			GameObject bullet = (GameObject)Instantiate(EnemyBulletGo);
			bullet.transform.position = transform.position;
			Vector2 direction = EnemyBoss.transform.position - bullet.transform.position;
			bullet.GetComponent<BulletBoss>().SetDirection(direction);


		}

	}
}
