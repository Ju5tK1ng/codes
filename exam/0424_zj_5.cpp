#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    int maxn = 1 << (n - 1);    // 除去出发点0, 1 ~ n - 1的城市集合
    vector<vector<int>> dp(n, vector<int>(maxn, 0x3f3f3f3f));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = m[i][0];
    }
    // dp[i][j]: 从i出发，经过j的集合，再回到0
    for (int j = 1; j < maxn; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || !(j & 1 << (i - 1)))
            {
                for (int k = 1; k < n; k++)
                {
                    if (j & 1 << (k - 1))
                    {
                        dp[i][j] = min(dp[i][j], m[i][k] + dp[k][j & ~(1 << (k - 1))]);
                    }
                }
            }
        }
    }
    cout << dp[0][maxn - 1] << endl;
    return 0;
}