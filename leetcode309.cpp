#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2)
    {
        return 0;
    }
    int buy[n], sell[n], have[n], cool[n];
    have[0] = buy[0] = prices[0];
    cool[0] = sell[0] = 0;
    for (int i = 1; i < n; i++)
    {
        buy[i] = prices[i] - cool[i - 1];
        have[i] = min(have[i - 1], buy[i - 1]);
        sell[i] = prices[i] - have[i];
        cool[i] = max(cool[i - 1], sell[i - 1]);
    }
    return max(sell[n - 1], cool[n - 1]);
}
// 1.1
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2)
    {
        return 0;
    }
    int buy[n], sell[n], cool[n];
    buy[0] = prices[0];
    cool[0] = sell[0] = 0;
    for (int i = 1; i < n; i++)
    {
        buy[i] = min(buy[i - 1], prices[i] - cool[i - 1]);
        sell[i] = prices[i] - buy[i - 1];
        cool[i] = max(cool[i - 1], sell[i - 1]);
    }
    return max(sell[n - 1], cool[n - 1]);
}
int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(prices) << endl;
    return 0;
}