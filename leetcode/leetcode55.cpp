#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int index = q.front();
            q.pop();
            for (int i = index + 1; i <= index + nums[index]; i++)
            {
                if (i == n - 1)
                {
                    return true;
                }
                q.push(i);
            }
            nums[index] = 0;
        }
        return false;
    }
};

// 1.1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        queue<int> q;
        unordered_set<int> us;
        q.push(0);
        while (!q.empty())
        {
            int index = q.front();
            q.pop();
            if (index + nums[index] >= n - 1)
            {
                return true;
            }
            for (int i = index + 1; i <= index + nums[index]; i++)
            {
                if (!us.count(i))
                {
                    q.push(i);
                    us.insert(i);
                }
            }
            nums[index] = 0;
        }
        return false;
    }
};

// 2.0
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxr = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > maxr)
            {
                return false;
            }
            maxr = max(maxr, i + nums[i]);
        }
        return true;
    }
};
