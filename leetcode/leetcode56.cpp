#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int>& a, vector<int>& b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(), i = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        vector<int> t(2);
        while (i < n)
        {
            t[0] = intervals[i][0];
            t[1] = intervals[i][1];
            i++;
            while (i < n && intervals[i][0] <= t[1])
            {
                t[1] = max(t[1], intervals[i][1]);
                i++;
            }
            ans.push_back(t);
        }
        return ans;
    }
};