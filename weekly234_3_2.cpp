#include<bits/stdc++.h>
using namespace std;
// 2.0
string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> m;
    for (auto it : knowledge)
    {
        m[it[0]] = it[1];
    }
    int start;
    string ans, sub;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            i++;
            while (s[i] != ')')
            {
                sub += s[i];
                i++;
            }
            if (m.count(sub))
            {
                ans += m[sub];
            }
            else
            {
                ans += '?';
            }
            sub = "";
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}