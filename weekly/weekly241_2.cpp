#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        int zero = 0, one = 0, ans = 0;
        for (char& c : s)
        {
            if (c == '0')
            {
                zero++;
            }
            else
            {
                one++;
            }
        }
        if (zero == one)
        {
            int a01 = 0, a10 = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (i % 2)
                {
                    s[i] == '0' ? a01++ : a10++;
                }
                else
                {
                    s[i] == '0' ? a10++ : a01++;
                }
            }
            ans = min(a01, a10);
        }
        else if (zero == one + 1)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (i % 2)
                {
                    if (s[i] == '0')
                    {
                        ans++;
                    }
                }
                else
                {
                    if (s[i] == '1')
                    {
                        ans++;
                    }
                }
            }
        }
        else if (zero == one - 1)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (i % 2)
                {
                    if (s[i] == '1')
                    {
                        ans++;
                    }
                }
                else
                {
                    if (s[i] == '0')
                    {
                        ans++;
                    }
                }
            }
        }
        else
        {
            ans = -2;
        }
        return ans / 2;
    }
};