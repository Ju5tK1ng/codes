#include <bits/stdc++.h>
using namespace std;
// // 1.0
// class Solution {
// public:
//     static bool cmp(string& a, string& b)
//     {
//         return a + b > b + a;
//     }

//     string largestNumber(vector<int>& nums) {
//         vector<string> vs;
//         for (int& i : nums)
//         {
//             vs.push_back(to_string(i));
//         }
//         sort(vs.begin(), vs.end(), cmp);
//         string ans = "";
//         for (string& s : vs)
//         {
//             ans += s;
//         }
//         if (ans[0] == '0')
//         {
//             ans = '0';
//         }
//         return ans;
//     }
// };

class Solution {
public:
    static bool cmp(int& x, int& y)
    {
        string a = to_string(x);
        string b = to_string(y);
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans = "";
        for (int& i : nums)
        {
            ans += to_string(i);
        }
        if (ans[0] == '0')
        {
            ans = '0';
        }
        return ans;
    }
};
