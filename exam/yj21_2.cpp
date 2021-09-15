#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    size_t a[10010];
public:
    int step(int n) {
        memset(a, 0, sizeof(a));
        a[1] = 1;
        a[2] = 3;
        a[3] = 12;
        a[4] = 55;
        for (size_t i = 5; i <= 9500; i++)
        {
            a[i] = a[i - 1] * (3 * i - 2) * (3 * i - 1) * 3 / (2 * i + 1) / i / 2;
        }
        return a[n] % 10000;
    }
};
