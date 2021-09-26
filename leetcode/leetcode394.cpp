#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string ans;
        vector<pair<int, int>> pos;
        int p;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                string cnt = "";
                while(s[i] != '[')
                {
                    cnt += s[i];
                    i++;
                }
                pos.push_back(make_pair(ans.size(), stoi(cnt) - 1));
            }
            else if (s[i] == ']')
            {
                int n = ans.size() - pos.back().first;
                for (int j = 0; j < pos.back().second; j++)
                {
                    ans += ans.substr(pos.back().first, n);
                }
                pos.pop_back();
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};
