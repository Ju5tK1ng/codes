#include<bits/stdc++.h>
using namespace std;
struct Comp
{
    bool operator() (vector<int>& v1, vector<int>& v2)
    {
        return v1[2] < v2[2];
    }
};

int storeWater(vector<int>& bucket, vector<int>& vat) {
    int n = bucket.size(), ans = 0, maxn;
    vector<int> v(3);
    priority_queue<vector<int>, vector<vector<int>>, Comp> q;
    for (int i = 0; i < n; i++)
    {
        v[0] = bucket[i];
        v[1] = vat[i];
        if (v[1] == 0)
        {
            v[2] = 0;
        }
        else if (v[0] == 0)
        {
            v[0]++;
            ans++;
            v[2] = (v[1] - 1) / v[0] + 1;
        }
        else
        {
            v[2] = (v[1] - 1) / v[0] + 1;
        }
        q.push(v);
    }
    while (true)
    {
        maxn = q.top()[2];
        if (maxn <= 1)
        {
            break;
        }
        int cur = ans;
        while (q.top()[2] == maxn)
        {
            v = q.top();
            q.pop();
            while(v[2] == maxn)
            {
                v[0]++;
                cur++;
                v[2] = (v[1] - 1) / v[0] + 1;
            }
            q.push(v);
        }
        if (ans + maxn < cur + q.top()[2])
        {
            break;
        }
        else
        {
            ans = cur;
        }
    }
    return ans + maxn;
}

// 1.1
int storeWater(vector<int>& bucket, vector<int>& vat) {
    int ans = 1e9;
    if(*max_element(vat.begin(), vat.end()) == 0)
    {
        return 0;
    }
    for(int i = 1;i <= 10000; i++){
        int n = vat.size(), sum = i;
        for(int j = 0; j < n; j++){
            sum += max(0, (vat[j] - 1) / i + 1 - bucket[j]);
        }
        ans = min(ans, sum);
    }
    return ans;
}