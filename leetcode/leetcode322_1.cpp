#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    int dp[10010];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int &coin : coins)
    {
        for (int j = coin; j <= amount; j++)
        {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }
    if (dp[amount] != 0x3f3f3f3f)
    {
        return dp[amount];
    }
    else
    {
        return -1;
    }
}
int main()
{
    vector<int> coins;
    int amount, n, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        coins.push_back(t);
    }
    cin >> amount;
    cout << coinChange(coins, amount) << endl;
    return 0;
}