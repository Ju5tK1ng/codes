#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int ans = 0;
        for (int& i : nums)
        {
            um[i]++;
            ans += um[i - k] + um[i + k];
        }
        return ans;
    }
};
