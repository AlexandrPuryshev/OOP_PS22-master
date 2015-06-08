using UnityEngine;
using System.Collections;

public class Gun : MonoBehaviour
{
	public Rigidbody2D rocket;				// Prefab of the rocket.
	public Rigidbody2D bullet;
	public GameObject gun1;
	public GameObject gun2;
	
	public float speedRocket = 20f;				// The speed the rocket will fire at.
	public float speedBullet = 100f;


	private PlayerControl playerCtrl;		// Reference to the PlayerControl script.
	private Animator anim;					// Reference to the Animator component.
	private int curWeapon;
	private bool GunFlag = false;


	void Start()
	{
		curWeapon = 2;
		Switch();
	}
	void Awake()
	{
		// Setting up the references.
		anim = transform.root.gameObject.GetComponent<Animator>();
		playerCtrl = transform.root.GetComponent<PlayerControl>();
	}

	void Coup(Rigidbody2D rigidValue, float vectorValue, float vectorSpeed)
	{
		Rigidbody2D bulletInstance = Instantiate(rigidValue, transform.position, Quaternion.Euler(new Vector3(0, 0, vectorValue))) as Rigidbody2D;
		bulletInstance.velocity = new Vector2(vectorSpeed, 0);
	}


	void Shoot(float speed, Rigidbody2D rigidValue)
	{
		// If the fire button is pressed...
		if (Input.GetButtonDown("Fire1"))
		{
			// ... set the animator Shoot trigger parameter and play the audioclip.
			anim.SetTrigger("Shoot");
			GetComponent<AudioSource>().Play();

			// If the player is facing right...
			if (playerCtrl.facingRight)
			{
				// ... instantiate the rocket facing right and set it's velocity to the right. 
				Coup(rigidValue, 0, speed);
			}
			else
			{
				// Otherwise instantiate the rocket facing left and set it's velocity to the left.
				Coup(rigidValue, 180f, -speed);
			}
		}
	}

	void NULL()
	{
		gun1.SetActive(false);
		gun2.SetActive(false);
	}

	void Switch()
	{
		if(curWeapon == 1)
		{
			NULL();
			gun1.SetActive(true);
		}
		else if(curWeapon == 2)
		{
			NULL();
			gun2.SetActive(true);
		}
	}

	void FixedUpdate()
	{
		if(GunFlag == true)
		{
			Shoot(speedRocket, rocket);
		}
		else
		{
			Shoot(speedBullet, bullet);
		}
	}

	void Update ()
	{
		if (Input.GetKeyDown("1"))
		{
			GunFlag = true;
			curWeapon = 1;
			Switch();
		}
		else if(Input.GetKeyDown("2"))
		{
			GunFlag = false;
			curWeapon = 2;
			Switch();
		}
	}
}
