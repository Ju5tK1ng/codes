#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (n == 1)
        {
            ans = a[0];
        }
        else if (n == 2)
        {
            ans = a[1];
        }
        else if (n == 3)
        {
            ans = a[0] + a[1] + a[2];
        }
        else
        {
            for (int i = 1; i < n - 3; i++)
            {
                ans += a[0] + a[i];
            }
            ans += a[n - 3] + a[0];
            ans += a[n - 1] + a[1] * 2;
        }
        cout << ans << endl;
    }
    return 0;
}