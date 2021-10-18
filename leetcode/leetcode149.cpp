#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, int> um;
        int n = points.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            um.clear();
            for (int j = i + 1; j < n; j++)
            {
                if (points[i][0] - points[j][0] == 0)
                {
                    um[INT_MAX]++;
                }
                else
                {
                    um[double(points[i][1] - points[j][1]) / (points[i][0] - points[j][0])]++;
                }
            }
            for (auto& p : um)
            {
                ans = max(ans, p.second);
            }
        }
        return ans + 1;
    }
};
