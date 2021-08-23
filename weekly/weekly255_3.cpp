#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        bitset<5000> b;
        b.set(0);
        for (int i = 0; i < n; i++)
        {
            bitset<5000> c;
            for (int j = 0; j < m; j++)
            {
                c |= b << mat[i][j];
            }
            b = c;
        }
        int ans = 4900;
        for (int i = 0; i < 4900; i++)
        {
            if (b[i])
            {
                ans = min(ans, abs(i - target));
            }
        }
        return ans;
    }
};