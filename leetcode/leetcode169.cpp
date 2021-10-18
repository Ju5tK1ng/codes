#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = 0, cnt = 0;
        for (int& num : nums)
        {
            if (cnt == 0)
            {
                cur = num;
                cnt = 1;
            }
            else if (cur == num)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return cur;
    }
};
