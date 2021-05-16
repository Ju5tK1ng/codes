#include<bits/stdc++.h>
using namespace std;
string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> m;
    for (auto it : knowledge)
    {
        m[it[0]] = it[1];
    }
    int start;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            start = i;
        }
        else if (s[i] == ')')
        {
            string sub = s.substr(start + 1, i - start - 1);
            // cout << sub << endl;
            if (m.count(sub))
            {
                s.replace(start, i - start + 1, m[sub]);
                i = start + m[sub].size() - 1;
            }
            else
            {
                s.replace(start, i - start + 1, "?");
                i = start;
            }          
        }
    }
    return s;
}