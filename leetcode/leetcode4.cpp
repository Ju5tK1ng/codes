#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.size(), m = nums2.size();
        int l = 0, r = n, m1 = 0, m2 = 0;
        while (l <= r)  // 左闭右闭
        {
            int i = l + (r - l) / 2, j = (n + m + 1) / 2 - i;
            int numim1 = i == 0 ? INT_MIN : nums1[i - 1];
            int numi = i == n ? INT_MAX : nums1[i];
            int numjm1 = j == 0 ? INT_MIN : nums2[j - 1];
            int numj = j == m ? INT_MAX : nums2[j];
            if (numim1 <= numj)
            {
                m1 = max(numim1, numjm1);
                m2 = min(numi, numj);
                l = i + 1;
            }
            else
            {
                r = i -1;
            }
        }
        return (n + m) % 2 ? m1 : (m1 + m2) / 2.0;
    }
};