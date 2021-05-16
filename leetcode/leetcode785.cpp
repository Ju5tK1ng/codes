#include<bits/stdc++.h>
using namespace std; 
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    int a[n];
    memset(a, 0, sizeof(a));
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            q.push(i);
            a[i] = 1;
        }
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (int& num : graph[t])
            {
                if (a[num] == 0)
                {
                    q.push(num);
                    a[num] = a[t] == 2 ? 1 : 2;
                }
                else if (a[num] == a[t])
                {
                    return false;
                }
            }
        }
    }
    return  true;
}