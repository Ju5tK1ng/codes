#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int ans;
public:
    void mergeSort(vector<int>& nums, vector<int>& T, int l, int r)
    {
        if (r - l <= 1)
        {
            return;
        }
        int m = l + (r - l) / 2;
        mergeSort(nums, T, l, m);
        mergeSort(nums, T, m, r);
        int p = l, q = m, i = l;
        while (p < m || q < r)
        {
            if (q >= r || p < m && nums[p] <= nums[q])
            {
                T[i++] = nums[p++];
            }
            else
            {
                ans += m - p;
                T[i++] = nums[q++];
            }
        }
        for (int i = l; i < r; i++)
        {
            nums[i] = T[i];
        }
    }

    int reversePairs(vector<int>& nums) {
        ans = 0;
        vector<int> T(nums);
        mergeSort(nums, T, 0, nums.size());
        return ans;
    }
};
