using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Control : MonoBehaviour
{
    public GameObject signalS;
    public GameObject signalN;
    public GameObject signalW;
    public GameObject signalE;
    public Signal SignalS;
    public Signal SignalN;
    public Signal SignalW;
    public Signal SignalE;
    public List<GameObject> prefab;
    public List<GameObject> chart;
    private GameObject nowCar;
    private List<float> timer;
    private bool running;
    public int greenTimeSN;
    public float nowtime;
    public float maxNS;
    public float maxWE;
    // Start is called before the first frame update
    void Start()
    {
        SignalS = signalS.GetComponent<Signal>();
        SignalN = signalN.GetComponent<Signal>();
        SignalW = signalW.GetComponent<Signal>();
        SignalE = signalE.GetComponent<Signal>();
        timer = new List<float>();
        for (int i = 0; i < 8; i++)
        {
            timer.Add(Random.Range(0f, 2f));
        }
        running = false;
        greenTimeSN = 15;
        nowtime = 0f;
    }

    // Update is called once per frame
    void Update()
    {
        if (running)
        {
            nowtime -= Time.deltaTime;
            if (nowtime < 0)
            {
                if (SignalS.cnt != 0)
                {
                    SignalS.flow = 1.0f * SignalS.cnt / SignalS.greenTime;
                    SignalN.flow = 1.0f * SignalN.cnt / SignalN.greenTime;
                    SignalW.flow = 1.0f * SignalW.cnt / SignalW.greenTime;
                    SignalE.flow = 1.0f * SignalE.cnt / SignalE.greenTime;
                    chart[0].GetComponent<Chart>().AddPosition(SignalE.flow);
                    chart[2].GetComponent<Chart>().AddPosition(SignalW.flow);
                    chart[4].GetComponent<Chart>().AddPosition(SignalS.flow);
                    chart[6].GetComponent<Chart>().AddPosition(SignalN.flow);
                    greenTimeSN = (int)Mathf.Round(30f * (SignalS.flow + SignalN.flow) / (SignalS.flow + SignalN.flow + SignalW.flow + SignalE.flow));
                    chart[1].GetComponent<Chart2>().AddPosition(30 - greenTimeSN);
                    chart[3].GetComponent<Chart2>().AddPosition(30 - greenTimeSN);
                    chart[5].GetComponent<Chart2>().AddPosition(greenTimeSN);
                    chart[7].GetComponent<Chart2>().AddPosition(greenTimeSN);
                }
                maxNS = Random.Range(2f, 4f);
                maxWE = Random.Range(2f, 4f);

                nowtime = 30f;
                SignalS.greenTime = SignalN.greenTime = greenTimeSN;
                SignalS.leftTime = SignalN.leftTime = 30f;
                SignalS.curLeftTime = SignalN.curLeftTime = SignalS.greenTime - 3f;
                SignalS.cnt = SignalN.cnt = 0;
                SignalS.line1 = SignalN.line1 = SignalS.line2 = SignalN.line2 = 1.5f;
                SignalS.state = SignalN.state = 0;

                SignalW.greenTime = SignalE.greenTime = 30 - greenTimeSN;
                SignalW.leftTime = SignalE.leftTime = 30f;
                SignalW.curLeftTime = SignalE.curLeftTime = 30f - SignalW.greenTime;
                SignalW.cnt = SignalE.cnt = 0;
                SignalW.state = SignalE.state = 2;
            }
            for (int i = 0; i < 8; i++)
            {
                switch (i)
                {
                    case 0:
                        if (SignalS.line1 <= 4.5f)
                        {
                            timer[i] -= Time.deltaTime;
                        }
                        if (timer[i] < 0)
                        {
                            timer[i] = Random.Range(1f, maxNS);
                            nowCar = Instantiate(prefab[i], prefab[i].GetComponent<Transform>().position, prefab[i].GetComponent<Transform>().rotation);
                            nowCar.GetComponent<Car>().velocity = new Vector3(0, 0, 2);
                            nowCar.GetComponent<Car>().signal = SignalS;
                            nowCar.GetComponent<Car>().road = 1;
                        }
                        break;
                    case 1:
                        if (SignalS.line2 <= 4.5f)
                        {
                            timer[i] -= Time.deltaTime;
                        }
                        if (timer[i] < 0)
                        {
                            timer[i] = Random.Range(1f, maxNS);
                            nowCar = Instantiate(prefab[i], prefab[i].GetComponent<Transform>().position, prefab[i].GetComponent<Transform>().rotation);
                            nowCar.GetComponent<Car>().velocity = new Vector3(0, 0, 2);
                            nowCar.GetComponent<Car>().signal = SignalS;
                            nowCar.GetComponent<Car>().road = 2;
                        }
                        break;
                    case 2:
                        if (SignalN.line1 <= 4.5f)
                        {
                            timer[i] -= Time.deltaTime;
                        }
                        if (timer[i] < 0)
                        {
                            timer[i] = Random.Range(1f, maxNS);
                            nowCar = Instantiate(prefab[i], prefab[i].GetComponent<Transform>().position, prefab[i].GetComponent<Transform>().rotation);
                            nowCar.GetComponent<Car>().velocity = new Vector3(0, 0, -2);
                            nowCar.GetComponent<Car>().signal = SignalN;
                            nowCar.GetComponent<Car>().road = 1;
                        }
                        break;
                    case 3:
                        if (SignalN.line2 <= 4.5f)
                        {
                            timer[i] -= Time.deltaTime;
                        }
                        if (timer[i] < 0)
                        {
                            timer[i] = Random.Range(1f, maxNS);
                            nowCar = Instantiate(prefab[i], prefab[i].GetComponent<Transform>().position, prefab[i].GetComponent<Transform>().rotation);
                            nowCar.GetComponent<Car>().velocity = new Vector3(0, 0, -2);
                            nowCar.GetComponent<Car>().signal = SignalN;
                            nowCar.GetComponent<Car>().road = 2;
                        }
                        break;
                    case 4:
                        if (SignalW.line1 <= 4.5f)
                        {
                            timer[i] -= Time.deltaTime;
                        }
                        if (timer[i] < 0)
                        {
                            timer[i] = Random.Range(1f, maxWE);
                            nowCar = Instantiate(prefab[i], prefab[i].GetComponent<Transform>().position, prefab[i].GetComponent<Transform>().rotation);
                            nowCar.GetComponent<Car>().velocity = new Vector3(2, 0, 0);
                            nowCar.GetComponent<Car>().signal = SignalW;
                            nowCar.GetComponent<Car>().road = 1;
                        }
                        break;
                    case 5:
                        if (SignalW.line2 <= 4.5f)
                        {
                            timer[i] -= Time.deltaTime;
                        }
                        if (timer[i] < 0)
                        {
                            timer[i] = Random.Range(1f, maxWE);
                            nowCar = Instantiate(prefab[i], prefab[i].GetComponent<Transform>().position, prefab[i].GetComponent<Transform>().rotation);
                            nowCar.GetComponent<Car>().velocity = new Vector3(2, 0, 0);
                            nowCar.GetComponent<Car>().signal = SignalW;
                            nowCar.GetComponent<Car>().road = 2;
                        }
                        break;
                    case 6:
                        if (SignalE.line1 <= 4.5f)
                        {
                            timer[i] -= Time.deltaTime;
                        }
                        if (timer[i] < 0)
                        {
                            timer[i] = Random.Range(1f, maxWE);
                            nowCar = Instantiate(prefab[i], prefab[i].GetComponent<Transform>().position, prefab[i].GetComponent<Transform>().rotation);
                            nowCar.GetComponent<Car>().velocity = new Vector3(-2, 0, 0);
                            nowCar.GetComponent<Car>().signal = SignalE;
                            nowCar.GetComponent<Car>().road = 1;
                        }
                        break;
                    case 7:
                        if (SignalE.line2 <= 4.5f)
                        {
                            timer[i] -= Time.deltaTime;
                        }
                        if (timer[i] < 0)
                        {
                            timer[i] = Random.Range(1f, maxWE);
                            nowCar = Instantiate(prefab[i], prefab[i].GetComponent<Transform>().position, prefab[i].GetComponent<Transform>().rotation);
                            nowCar.GetComponent<Car>().velocity = new Vector3(-2, 0, 0);
                            nowCar.GetComponent<Car>().signal = SignalE;
                            nowCar.GetComponent<Car>().road = 2;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    public void OnClick_Start()
    {
        running = true;
    }

    public void OnClick_End()
    {
        UnityEngine.SceneManagement.SceneManager.LoadScene("SampleScene");
    }
}
