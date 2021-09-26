#include <bits/stdc++.h>
using namespace std;
// unordered_map<int, unordered_set<int>> us;
bool a[1010][1010];
int T, n, m, k, u, v, pre, cur;
int main()
{
    cin >> T;
    while (T--)
    {
        // us.clear();
        memset(a, 0, sizeof(a));
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
        {
            // a[i][i] = true;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            // us[u].insert(v);
            // us[v].insert(u);
            a[u][v] = a[v][u] = true;
        }
        cin >> pre;
        bool ok = true;
        for (int i = 1; i < k; i++)
        {
            cin >> cur;
            if (a[cur][pre])
            {
                pre = cur;
            }
            else
            {
                ok = false;
            }
        }
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
