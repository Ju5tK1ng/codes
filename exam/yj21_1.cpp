#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int increaseInterval(vector<int>& a) {
        vector<int> sum;
        sum.push_back(0);
        for (int& i : a)
        {
            sum.push_back(sum.back() + i);
        }
        int ans = 1, presum = sum[1], pre = 1, i = 2;
        while (i < a.size())
        {
            if (sum[i] - sum[pre] > presum && sum[a.size()] - sum[i] > sum[i] - sum[pre])
            {
                ans++;
                presum = sum[i] - sum[pre];
                pre = i;
            }
            i++;
        }
        return ans;
    }
};
