#include<bits/stdc++.h>
using namespace std;
// 1.1
int findCircleNum(vector<vector<int>>& isConnected) {
    int ans = 0, n = isConnected.size();
    vector<bool> visited(n, false);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            ans++;
            s.push(i);
            while (!s.empty())
            {
                int t = s.top();
                s.pop();
                for (int j = 0; j < n; j++)
                {
                    if (isConnected[t][j] == 1 && !visited[j])
                    {
                        visited[j] = true;
                        s.push(j);
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> isConnected;
    for (int i = 0; i < n; i++)
    {
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        isConnected.push_back(v);
    }
    cout << findCircleNum(isConnected) << endl;
    return 0;
}