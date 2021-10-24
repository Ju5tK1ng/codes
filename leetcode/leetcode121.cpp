#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = prices[0], ans = 0;
        for (int price : prices)
        {
            minn = min(minn, price);
            ans = max(ans, price - minn);
        }
        return ans;
    }
};
