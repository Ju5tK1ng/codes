using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Car : MonoBehaviour
{
    private Rigidbody rigid;
    public Vector3 velocity;
    public Vector3 oldV;
    public Signal signal;
    private bool cnt;
    public int road;
    // Start is called before the first frame update
    void Start()
    {
        cnt = false;
        oldV = Vector3.zero;
        rigid = GetComponent<Rigidbody>();
        gameObject.GetComponent<MeshRenderer>().material.color = new Color(Random.Range(0f, 1f), Random.Range(0f, 1f), Random.Range(0f, 1f));
    }

    // Update is called once per frame
    void Update()
    {
        rigid.position += velocity * Time.deltaTime;
        if (road == 1)
        {
            if (oldV == Vector3.zero && signal.state != 0 && (Mathf.Abs(velocity.x / -2 * rigid.position.x - signal.line1) < 0.2f || Mathf.Abs(velocity.z / -2 * rigid.position.z - signal.line1) < 0.2f))
            {
                signal.line1 += 1.5f;
                oldV = velocity;
                velocity = Vector3.zero;
            }
        }
        else if (road == 2)
        {
            if (oldV == Vector3.zero && signal.state != 0 && (Mathf.Abs(velocity.x / -2 * rigid.position.x - signal.line2) < 0.2f || Mathf.Abs(velocity.z / -2 * rigid.position.z - signal.line2) < 0.2f))
            {
                signal.line2 += 1.5f;
                oldV = velocity;
                velocity = Vector3.zero;
            }
        }
        if (signal.state == 0 && cnt == false && (Mathf.Abs(velocity.x / -2 * rigid.position.x - 1.5f) < 0.1f || Mathf.Abs(velocity.z / -2 * rigid.position.z - 1.5f) < 0.1f))
        {
            cnt = true;
            signal.cnt ++;
        }
        if (oldV != Vector3.zero && signal.state == 0)
        {
            velocity = oldV;
            oldV = Vector3.zero;
        }
        if (rigid.position.y < 0)
        {
            Destroy(gameObject);
        }
    }
}
