#include<bits/stdc++.h>
using namespace std;
int dp[1 << 20], sum[1 << 20];
int main()
{
    int n;
    cin >> n;
    const int MAXN = 1 << n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(i & 1 << j))
            {
                int k = i | 1 << j;
                sum[k] = sum[i] + v[j].second;
                dp[k] = min(dp[k], dp[i] + max(0, sum[k] - v[j].first));
            }
        }
    }
    cout << dp[MAXN - 1] << endl;
    return 0;
}