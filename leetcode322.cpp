#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int a[10010];
    memset(a, 0x3f, sizeof(a));
    a[0] = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            a[j] = min(a[j], a[j - coins[i]] + 1);
        }
    }
    if (a[amount] != 0x3f3f3f3f)
    {
        return a[amount];
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