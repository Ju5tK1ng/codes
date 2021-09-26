#include <bits/stdc++.h>
using namespace std;
int n, m, t, l = 0, r = 1000000000;
int a[100010];

bool ok(int m, int mid)
{
    for (int i = 0; i < n; i++)
    {
        if (mid > a[i] && m >= 0)
        {
            m -= mid - a[i];
        }
    }
    return m >= 0;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (l < r)
    {
        int mid = l + (r - l + 1) / 2;
        // cout << l << '\t' << mid << '\t' << r << endl;
        if (ok(m, mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}
