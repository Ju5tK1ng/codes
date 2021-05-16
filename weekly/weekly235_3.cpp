#include<bits/stdc++.h>
using namespace std; 
int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    const int mod = 1e9 + 7;
    vector<int> nums3 = nums1;
    sort(nums3.begin(), nums3.end());
    int mincha;
    int maxcha = 0;
    long ans = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
        int num = abs(nums1[i] - nums2[i]);
        ans = ans % mod + num % mod;
        auto it = lower_bound(nums3.begin() + 1, nums3.end() - 1, nums2[i]);
        mincha = min(abs(*it - nums2[i]), abs(*(it - 1) - nums2[i]));
        maxcha = max(maxcha, num - mincha);
        // cout << cha[i] << mincha << endl;
    }
    ans -= maxcha;
    return ans % mod;
}