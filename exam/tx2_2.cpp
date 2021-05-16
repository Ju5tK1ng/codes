#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans;
    cin >> n;
    bool b[n];
    memset(b, false, sizeof(b));
    ans = n;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; i++)
    {
        if (!b[i] && !b[i + 1] && s[i] - '0' + s[i + 1] - '0' == 10)
        {
            ans -= 2;
            b[i] = b[i + 1] = true;
            int t = 1;
            int t2 = 1;
            while (i - t >= 0 && b[i - t])
            {
                t++;
            }
            while (i + 1 + t2 <= n - 1 && b[i + 1 + t2])
            {
                t2++;
            }
            while (i - t >= 0 && i + 1 + t2 <= n - 1 && !b[i - t] && !b[i + 1 + t2] && s[i - t] - '0' + s[i + 1 + t2] - '0' == 10)
            {
                b[i - t] = b[i + 1 + t2] = true;
                ans -= 2;
                t++;
                t2++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}