#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        arr.push_back(INT_MIN);
        while (l < r)
        {
            int m = l + (r - l + 1) / 2;
            if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1])
            {
                return m;
            }
            else if (arr[m] > arr[m - 1])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }
};
