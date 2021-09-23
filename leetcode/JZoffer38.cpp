#include <bits/stdc++.h>
using namespace std;
// 同lc46
class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> ans;
        ans.push_back(s);
        while (next_permutation(s.begin(), s.end()))
        {
            ans.push_back(s);
        }
        return ans;
    }
};
