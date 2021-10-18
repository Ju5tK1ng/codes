#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

// 1.1
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int dq[100010], head = 0, tail = -1;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (head <= tail && dq[head] == i - k)
            {
                head++;
            }
            while (head <= tail && nums[dq[tail]] < nums[i])
            {
                tail--;
            }
            dq[++tail] = i;
            if (i >= k - 1)
            {
                ans.push_back(nums[dq[head]]);
            }
        }
        return ans;
    }
};
