#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<long long> presum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            presum[i + 1] = presum[i] + nums[i];
        }
        stack<int> s;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && nums[i] <= nums[s.top()])
            {
                s.pop();
            }
            l[i] = s.empty() ? 0 : s.top() + 1;
            s.push(i);
        }
        s = stack<int>();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && nums[i] <= nums[s.top()])
            {
                s.pop();
            }
            r[i] = s.empty() ? n : s.top();
            s.push(i);
            ans = max(ans, nums[i] * (presum[r[i]] - presum[l[i]]));
        }
        return ans % ((int)1e9 + 7); 
    }
};