using UnityEngine;
using System.Collections;

public class BulletBoss : MonoBehaviour {

	// Use this for initialization
    public float speed = 10f;			//How fast the bullet moves
    Vector2 _direction;
    bool isReady;


    void Awake()
    {
        isReady = false;
    }

    void Start()
    {

    }

    public void SetDirection(Vector2 direction)
    {
        _direction = direction.normalized;
        isReady = true;
    }

    void Update()
    {
        if (isReady)
        {
            Vector2 position = transform.position;
            position += _direction * speed * Time.deltaTime;
            transform.position = position;
            Vector2 min = Camera.main.ViewportToWorldPoint(new Vector2(0, 0));
            Vector2 max = Camera.main.ViewportToWorldPoint(new Vector2(1, 1));
            if ((transform.position.x < min.x) || (transform.position.x > max.x)
                || (transform.position.y < min.y) || (transform.position.y > max.y))
            {
                Destroy(gameObject);
            }
        }
    }
}
