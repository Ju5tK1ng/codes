#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ans = 0, i = 0, j = 0;
        while (i < m)
        {
            while (j + 1 < n && (nums1[i] <= nums2[j + 1] || j < i))
            {
                j++;
            }
            if (nums1[i] <= nums2[j])
            {
                ans = max(ans, j - i);
            }
            i++;
        }
        return ans;
    }
};
