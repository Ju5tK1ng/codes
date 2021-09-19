#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main()
{
    int T, n, m;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        m--;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int l = m - 1, r = m + 1;
        while (l >= 0 && a[l] <= a[m])
        {
            l--;
        }
        while (r < n && a[r] <= a[m])
        {
            r++;
        }
        int d = r - l - 1;
        for (; r < n; r++)
        {
            a[r - d] = a[r];
        }
        n -= d;
        m = 1;
        cout << a[0];
        for (int i = 1; i < n; i++)
        {
            cout << " " << a[i];
            if (a[i] != a[i - 1])
            {
                a[m++] = a[i];
            }
        }
        cout << endl;
        int ans = 1;
        for (int i = 1; i < m - 1; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
