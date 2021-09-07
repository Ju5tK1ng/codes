#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> l, r;
        int len = nums.size();
        l.push_back(0);
        r.push_back(0);
        for (int i = len - 1; i >= 0; i--)
        {
            r.push_back(r[len - i - 1] + nums[i]);
        }
        for (int i = 0; i < len; i++)
        {
            l.push_back(l[i] + nums[i]);
            if (l[i] == r[len - i])
            {
                return i + 1;
            }
        }
        return -1;
    }
};
