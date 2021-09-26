#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 2; i <= numRows; i++)
        {
            vector<int> t(i, 1);
            for (int j = 1; j < i - 1; j++)
            {
                t[j] = ans.back()[j - 1] + ans.back()[j];
            }
            ans.push_back(t);
        }
        return ans;
    }
};
