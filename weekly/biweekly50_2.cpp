#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans(m, 0);
        for (int i = 0; i < m; i++)
        {
            for (vector<int>& point : points)
            {
                if ((point[0] - queries[i][0]) * (point[0] - queries[i][0]) + (point[1] - queries[i][1]) * (point[1] - queries[i][1]) <= queries[i][2] * queries[i][2])
                {
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};