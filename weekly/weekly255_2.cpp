#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unsigned int s2i(string num)
    {
        unsigned int res = 0;
        for (char c : num)
        {
            res = res * 2 + (c - '0');
        }
        return res;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int length = nums.size(), ans;
        vector<unsigned int> v(length, 0);
        for (int i = 0; i < length; i++)
        {
            v[i] = s2i(nums[i]);
        }
        sort(v.begin(), v.end());
        if (v[0] != 0)
        {
            ans = 0;
        }
        else
        {
            ans = (1 << length) - 1;
            for (int i = 1; i < length; i++)
            {
                if (v[i] > v[i - 1] + 1)
                {
                    ans = v[i - 1] + 1;
                }
            }
        }
        string sans = "";
        while (length--)
        {
            if (ans % 2)
            {
                sans = '1' + sans;
            }
            else
            {
                sans = '0' + sans;
            }
            ans /= 2;
        }
        return sans;
    }
};

// 2.0
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[i][i] ^ 1);
        }
        return ans;
    }
};
