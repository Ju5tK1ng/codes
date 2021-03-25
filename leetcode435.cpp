#include<bits/stdc++.h>
using namespace std;
// 1.1
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty())
    {
        return 0;
    }
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b)
    {
        return a[1] < b[1];
    });
    int end = intervals[0][1], ans = 1;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] >= end)
        {
            ans++;
            end = intervals[i][1];
        }
    }
    return intervals.size() - ans;
}
int main()
{
    vector<vector<int>> intervals;
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> interval;
        cin >> t;
        interval.push_back(t);
        cin >> t;
        interval.push_back(t);
        intervals.push_back(interval);
    }
    cout << eraseOverlapIntervals(intervals) << endl;
    return 0;
}