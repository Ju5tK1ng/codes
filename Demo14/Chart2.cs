using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Chart2 : MonoBehaviour
{
    private LineRenderer lineRenderer;
    private int cnt;
    private float startX = -111.5f;
    private float startY = -63f;
    private float intervalX = 25.5f;
    private float intervalY = 4.87f;
    // Start is called before the first frame update
    void Start()
    {
        lineRenderer = gameObject.GetComponent<LineRenderer>();
        cnt = -1;
        lineRenderer.positionCount = 0;
 
        lineRenderer.startColor = new Color(255 / 255f, 192 / 255f, 0 / 255f);
        lineRenderer.endColor = new Color(255 / 255f, 192 / 255f, 0 / 255f);
        lineRenderer.startWidth = 0.02f;
        lineRenderer.endWidth = 0.02f;
        lineRenderer.useWorldSpace = false;
    }

    public void AddPosition(int time)
    {
        cnt++;
        if (lineRenderer.positionCount < 10)
        {
            lineRenderer.positionCount++;
        }
        float x = startX + (cnt % 10) * intervalX;
        float y = startY + time * intervalY;
        lineRenderer.SetPosition(cnt % 10, new Vector3(x, y, -1));
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
