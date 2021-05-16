#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, m, n, x, y, p, s, ans;
    cin >> T;
    while (T--)
    {
        s = 100000;
        ans = 0;
        cin >> m >> n >> x >> y >> p;
        if (s + m * x < p && m * x <= n * y)
        {
            cout << -1 << endl;
        }
        else
        {
            if (s + m * x < p)
            {
                int pp = p - m * x - s;
                ans = (pp - 1) / (m * x - n * y) + 1;
                s += ans * (m * x - n * y);
                ans *= (m + n);
            }
            ans += (p - s - 1) / x + 1;
            cout << ans << endl;
        } 
    }
    return 0;
}