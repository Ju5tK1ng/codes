#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<string> ans;
    int n;
public:
    void dfs(string& s, int l, int r)
    {
        if (l < r || l > n || r > n)
        {
            return;
        }
        if (l == n && r == n)
        {
            ans.push_back(s);
            return;
        }
        s[l + r] = '(';
        dfs(s, l + 1, r);
        s[l + r] = ')';
        dfs(s, l, r + 1);
    }

    vector<string> generateParenthesis(int n) {
        ans.clear();
        this->n = n;
        string s(2 * n, 0);
        dfs(s, 0, 0);
        return ans;
    }
};
