#include<bits/stdc++.h>
using namespace std;
int purchasePlans(vector<int>& nums, int target) {
    const int mod = 1e9 + 7;
    sort(nums.begin(), nums.end());
    long long index = upper_bound(nums.begin(), nums.end(), target / 2) - nums.begin() - 1;
    if (index < 0)
    {
        return 0;
    }
    int ans = index * (index + 1) / 2 % mod;
    int tail = index + 1;
    while (index >= 0 && tail < nums.size())
    {
        if (nums[index] + nums[tail] <= target)
        {
            ans = (ans + index + 1) % mod;
            tail++;
        }
        else
        {
            index--;
        }
    }
    return ans;
}

// 2.0
// int purchasePlans(vector<int>& nums, int target) {
//     const int mod = 1e9 + 7;
//     sort(nums.begin(), nums.end());
//     int ans = 0, j = nums.size() - 1;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         while (i < j && nums[i] + nums[j] > target)
//         {
//             j--;
//         }
//         if (i >= j)
//         {
//             break;
//         }
//         ans = (ans + j - i) % mod;
//     }
//     return ans;
// }