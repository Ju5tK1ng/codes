#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for (int& cost : costs)
        {
            if (coins >= cost)
            {
                ans++;
                coins -= cost;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};