#include<bits/stdc++.h>
using namespace std;
// 2.0
void dfs(vector<int>& coins, int amount, int index, int cnt, int& ans)
{
    if(amount == 0)
    {
        ans = min(ans, cnt);
        return;
    }
    if (index == coins.size())
    {
        return;
    }
    for (int k = amount / coins[index]; k >= 0 && k + cnt < ans; k--)
    {
        dfs(coins, amount - k * coins[index], index + 1, cnt + k, ans);
    }
}
int coinChange(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int ans = INT_MAX;
    dfs(coins, amount, 0, 0, ans);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
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