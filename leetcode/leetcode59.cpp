#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int cur = 0, l = 0, r = n - 1, t = 0, b = n - 1;
        while (l <= r && t <= b)
        {
            for (int j = l; j <= r; j++)
            {
                ans[t][j] = ++cur;
            }
            t++;
            for (int i = t; i <= b; i++)
            {
                ans[i][r] = ++cur;
            }
            r--;
            for (int j = r; j >= l; j--)
            {
                ans[b][j] = ++cur;
            }
            b--;
            for (int i = b; i >= t; i--)
            {
                ans[i][l] = ++cur;
            }
            l++;
        }
        return ans;
    }
};
