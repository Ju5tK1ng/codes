#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = n;
        stack<int, vector<int>> s;
        vector<int> l(n);
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                l[i] = -1;
            }
            else
            {
                l[i] = s.top();
            }
            s.push(i);
        }
        s = stack<int, vector<int>>();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                ans = max(ans, (n - l[i] - 1) * heights[i]);
            }
            else
            {
                ans = max(ans, (s.top() - l[i] - 1) * heights[i]);
            }
            s.push(i);
        }
        return ans;
    }
};
