#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        return us.size() != nums.size();
    }
};

// 1.1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (int& i : nums)
        {
            if (us.count(i))
            {
                return true;
            }
            us.insert(i);
        }
        return false;
    }
};

// 2.0
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                return true;
            }
        }
        return false;
    }
};
