using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Signal : MonoBehaviour
{
    public GameObject red;
    public GameObject yellow;
    public GameObject green;
    public int greenTime;
    public float leftTime;
    public float curLeftTime;
    public int cnt;
    public float flow;
    public float line1;
    public float line2;
    public int state;  // 0绿，1黄，2红，-1黑
    public Text cntText;
    // Start is called before the first frame update
    void Start()
    {
        cnt = 0;
        state = -1;
        line1 = line2 = 1.5f;
    }

    // Update is called once per frame
    void Update()
    {
        cntText.text = cnt.ToString();
        leftTime -= Time.deltaTime;
        curLeftTime -= Time.deltaTime;
        if (leftTime < 0)
        {
            state = -1;
        }
        else if (curLeftTime < 0)
        {
            switch(state)
            {
                case 0:
                    curLeftTime = 3f;
                    state = 1;
                    break;
                case 1:
                    curLeftTime = 30f - greenTime;
                    state = 2;
                    break;
                case 2:
                    line1 = line2 = 1.5f;
                    curLeftTime = greenTime - 3f;
                    state = 0;
                    break;
                default:
                    break;
            }
        }
        switch(state)
        {
            case 0:
                red.GetComponent<MeshRenderer>().material.color = Color.black;
                yellow.GetComponent<MeshRenderer>().material.color = Color.black;
                green.GetComponent<MeshRenderer>().material.color = Color.green;
                break;
            case 1:
                red.GetComponent<MeshRenderer>().material.color = Color.black;
                yellow.GetComponent<MeshRenderer>().material.color = Color.yellow;
                green.GetComponent<MeshRenderer>().material.color = Color.black;
                break;
            case 2:
                red.GetComponent<MeshRenderer>().material.color = Color.red;
                yellow.GetComponent<MeshRenderer>().material.color = Color.black;
                green.GetComponent<MeshRenderer>().material.color = Color.black;
                break;
            default:
                red.GetComponent<MeshRenderer>().material.color = Color.black;
                yellow.GetComponent<MeshRenderer>().material.color = Color.black;
                green.GetComponent<MeshRenderer>().material.color = Color.black;
                break;
        }
    }
}
