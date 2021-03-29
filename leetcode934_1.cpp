#include<bits/stdc++.h>
using namespace std;
vector<int> d = {-1, 0, 1, 0, -1};
void dfs(vector<vector<int>>& A, queue<pair<int, int>>& q, int i, int j, int m, int n)
{
    if (i < 0 || i >= m || j < 0 || j >= n || A[i][j] == -1)
    {
        return;
    }
    if (A[i][j] == 0)
    {
        q.push(pair<int, int>{i, j});
        return;
    }
    A[i][j] = -1;
    dfs(A, q, i - 1, j, m, n);
    dfs(A, q, i, j + 1, m, n);
    dfs(A, q, i + 1, j, m, n);
    dfs(A, q, i, j - 1, m, n);
}
int shortestBridge(vector<vector<int>>& A) {
    queue<pair<int, int>> q;
    int m = A.size(), n = A[0].size();
    bool fliped = false;
    for (int i = 0; i < m; i++)
    {
        if (fliped)
        {
            break;
        }
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                dfs(A, q, i, j, m, n);
                fliped = true;
                break;
            }
        }
    }
    int ans = 0;
    while(!q.empty())
    {
        ans++;
        int cnt = q.size();
        while(cnt--)
        {
            pair<int, int> t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = t.first + d[i], y = t.second + d[i + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && A[x][y] != -1)
                {
                    if (A[x][y] == 1)
                    {
                        return ans;
                    }
                    A[x][y] = -1;
                    q.push(pair<int, int>{x, y});
                }
            }
        }
    }
    return 0;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> A;
    for (int i = 0; i < m; i++)
    {
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        A.push_back(v);
    }
    cout << shortestBridge(A) << endl;
    return 0;
}