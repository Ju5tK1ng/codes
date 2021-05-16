#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[128] = {0}, head = 0, n = s.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            a[s[i]]++;
            while (a[s[i]] == 2)
            {
                a[s[head++]]--;
            }
            ans = max(ans, i - head + 1);
        }
        return ans;
    }
};