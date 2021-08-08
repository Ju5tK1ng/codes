#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        int ans = 0, cnt = 0;
        for (auto c : s)
        {
            if (c == '[')
            {
                cnt--;
            }
            else
            {
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans == 0 ? 0 : (ans - 1) / 2 + 1;
    }
};