#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> dp, ans;
        for (auto obstacle : obstacles )
        {
            if (dp.empty() || obstacle >= dp.back())
            {
                dp.push_back(obstacle);
                ans.push_back(dp.size());
            }
            else
            {
                auto it = upper_bound(dp.begin(), dp.end(), obstacle);
                ans.push_back(it - dp.begin() + 1);
                *it = obstacle;
            }
        }
        return ans;
    }
};