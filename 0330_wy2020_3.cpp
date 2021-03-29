#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int m, t, m1, t1, m2, t2, ans = 0;
        cin >> m >> t >> m1 >> t1 >> m2 >> t2;
        for (int i = 0; i < t; i++)
        {
            ans += m1 * ((i / t1 + 1) % 2) - m2 * ((i / t2 + 1) % 2);
            if (ans < 0)
            {
                ans = 0;
            }
            else if (ans > m)
            {
                ans = m;
            }
        }
        cout << ans << endl;
    }
    return 0;
}