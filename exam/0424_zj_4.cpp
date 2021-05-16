#include<bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> pre, cur;
int n, m, cnt, ans;
pair<int, int> t;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> m;
        while (m--)
        {
            cin >> cnt;
            while (cnt--)
            {
                cin >> t.first >> t.second;
                if (pre.count(t))
                {
                    cur[t] = pre[t] + 1;
                }
                else
                {
                    cur[t] = 1;
                }
                ans = max(ans, cur[t]);
            }
            pre = cur;
            cur.clear();
        }
    }
    cout << ans << endl;
    return 0;
}