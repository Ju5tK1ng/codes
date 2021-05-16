#include<bits/stdc++.h>
using namespace std;
int a[100010], dp[100010][7];
int main ()
{
    int t, cnt = 0;
    while (cin >> t)
    {
        a[cnt++] = t;
    }
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (j == 0 || dp[i][(j + a[i]) % 7] != 0 || dp[i][j] != 0)
            {
                dp[i + 1][(j + a[i]) % 7] = max(dp[i][(j + a[i]) % 7], dp[i][j] + a[i]);
            }
        }
    }
    cout << dp[cnt][0] << endl;
    return 0;
}