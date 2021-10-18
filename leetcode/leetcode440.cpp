#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while (k > 0)
        {
            long long cnt = 0, start = cur, end = cur + 1;
            while (start <= n)
            {
                cnt += min((long long)n + 1, end) - start;
                start *= 10;
                end *= 10;
            }
            if (cnt <= k)
            {
                cur++;
                k -= cnt;
            }
            else
            {
                cur *= 10;
                k--;
            }
        }
        return cur;
    }
};
