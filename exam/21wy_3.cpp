#include <bits/stdc++.h>
using namespace std;
int a[10010][10010];
int b[10010];
int main()
{
    int T, n, m1, m2, u, v;
    cin >> T;
    while (T--)
    {
        memset(a, 0x3f, sizeof(a));
        memset(b, -1, sizeof(b));
        cin >> n >> m1 >> m2;
        for (int i = 0; i < m1; i++)
        {
            cin >> u >> v;
            a[u][v] = a[v][u] = 1;
        }
        for (int i = 0; i < m2; i++)
        {
            cin >> u >> v;
            a[u][v] = a[v][u] = 0;
        }
        queue<int> q;
        q.push(1);
        b[1] = 0;
        vector<int> cnt(10010, 0);
        bool find = false;
        while (!find)
        {
            int size = q.size();
            while(size--)
            {
                int t = q.front();
                q.pop();
                if (t == n)
                {
                    cout << cnt[t] << endl;
                    find = true;
                    break;
                }
                for (int i = 1; i <= n; i++)
                {
                    if (b[i] == -1)
                    {
                        if (a[t][i] == 1)
                        {
                            cnt[i]++;
                            b[i] = 0;
                            q.push(i);
                        }
                        else if (a[t][i] == 0)
                        {
                            if (b[t] == 1)
                            {
                                cnt[i]++;
                            }
                            b[i] = 1;
                            q.push(i);
                        }
                    }
                }
                b[t] = 0;
            }
        }
    }
    return 0;
}
