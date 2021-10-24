#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        deque<int> q;
        for (int i = 0; i < n; i++)
        {
            if (!q.empty() && height[i] >= q.front())
            {
                int l = q.front();
                q.pop_front();
                while (!q.empty())
                {
                    ans += l - q.front();
                    q.pop_front();
                }
            }
            q.push_back(height[i]);
        }
        while (!q.empty())
        {
            int r = q.back();
            q.pop_back();
            while (!q.empty() && q.back() < r)
            {
                ans += r - q.back();
                q.pop_back();
            }
        }
        return ans;
    }
};

// 2.0
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, l = 0, r = height.size() - 1;
        for (int i = 1; i <= r; i++)
        {
            if (height[i] >= height[l])
            {
                int hl = height[l];
                while (++l < i)
                {
                    ans += hl - height[l];
                }
            }
        }
        while (l < r)
        {
            int hr = height[r];
            while (l < --r && height[r] < hr)
            {
                ans += hr - height[r];
            }
        }
        return ans;
    }
};

// 2.1
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, l = 0, r = height.size() - 1, hl = 0, hr = 0;
        while (l < r)
        {
            if (height[l] < height[r])
            {
                if (hl <= height[l])
                {
                    hl = height[l];
                }
                else
                {
                    ans += hl - height[l];
                }
                l++;
            }
            else
            {
                if (hr <= height[r])
                {
                    hr = height[r];
                }
                else
                {
                    ans += hr - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};
