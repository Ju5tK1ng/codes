#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int minn = prices[0], ans = 0;
    for (int price : prices)
    {
        minn = min(minn, price);
        ans = max(ans, price - minn);
    }
    return ans;
}
// 1.1
// int maxProfit(vector<int>& prices) {
//     int minn = prices[0], ans = 0;
//     for (int price : prices)
//     {
//         if (price <= minn)
//         {
//             minn = price;
//         }
//         else
//         {
//             ans = max(ans, price - minn);
//         }
//     }
//     return ans;
// }
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