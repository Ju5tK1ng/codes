#include<bits/stdc++.h>
using namespace std;
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n < 2)
    {
        return 0;
    }
    if (n <= k)
    {
        int sell = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                sell += prices[i] - prices[i - 1];
            }
        }
        return sell;
    }
    else
    {
        int buy[k + 1], sell[k + 1];
        memset(buy, 0x3f, sizeof(buy));
        memset(sell, 0, sizeof(sell));
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= k;j++)
            {
                buy[j] = min(buy[j], prices[i] - sell[j - 1]);
                sell[j] = max(sell[j], prices[i] - buy[j]);
            }
        }
        return sell[k];
    }
}
int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(k, prices) << endl;
    return 0;
}