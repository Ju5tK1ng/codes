#include <bits/stdc++.h>
using namespace std;
// // 1.0
// class Solution {
// private:
//     vector<string> ans;
// public:
//     void dfs(string s, string tmp, int cnt)
//     {
//         if (s.size() == 0 && cnt == 4)
//         {
//             tmp.pop_back();
//             ans.push_back(tmp);
//         }
//         for (int i = 0; i < min(3, (int)s.size()); i++)
//         {
//             string pre = s.substr(0, i + 1);
//             int prenum = atoi(pre.c_str());
//             if (prenum >= 0 && prenum < 256 && pre == to_string(prenum))
//             {
//                 dfs(s.substr(i + 1), tmp + pre + '.', cnt + 1);
//             }
//         }
//     }

//     vector<string> restoreIpAddresses(string s) {
//         ans.clear();
//         if (s.size() <= 12)
//         {
//             dfs(s, "", 0);
//         }
//         return ans;
//     }
// };

// 2.0
class Solution {
public:
    bool check(string& s)
    {
        int i = stoi(s);
        if (i < 256 && s == to_string(i))
        {
            return true;
        }
        return false;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for (int a = 1; a < 4; a++)
        {
            for (int b = 1; b < 4; b++)
            {
                for (int c = 1; c < 4; c++)
                {
                    for (int d = 1; d < 4; d++)
                    {
                        if (a + b + c + d == s.size())
                        {
                            string s1 = s.substr(0, a);
                            string s2 = s.substr(a, b);
                            string s3 = s.substr(a + b, c);
                            string s4 = s.substr(a + b + c);
                            if (check(s1) && check(s2) && check(s3) && check(s4))
                            {
                                ans.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
