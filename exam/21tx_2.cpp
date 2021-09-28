#include <bits/stdc++.h>
using namespace std;
int a[200010], T, n;
int b[200010];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            b[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i + a[i] < n && b[i + a[i]] > b[i])
            {
                b[i + a[i]] = b[i];
            }
            // cout << i << '\t' << b[i] << endl;
            ans = max(ans, a[i] - b[i] + i);
        }
        // for (int i = 0; i < n; i++)
        // {
        //     if (!b[i])
        //     {
        //         int t = i, sum = a[t];
        //         while (t + a[t] < n)
        //         {
        //             t += a[t];
        //             sum += a[t];
        //             b[t] = true;
        //         }
        //         ans = max(ans, sum);
        //     }
        // }
        cout << ans << endl;
    }
    return 0;
}
