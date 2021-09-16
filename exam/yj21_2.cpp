#include <bits/stdc++.h>
using namespace std;

void C(int m, int n) {
    size_t ans = 1;
    for (int i = m - n + 1, j = 1; j <= n; i++, j++) {
        ans = ans * i / j;
    }
    cout << ans / (2 * n + 1) << endl;
}


int main()
{
    int row = 50, col = 25;
    vector<size_t> pre(50, 0), cur(50, 0);
    pre[0] = cur[0] = 1;
    for (int r = 2; r < row; r++)
    {
        for (int c = 1; c < col; c++)
        {
            if (c * 2 > r)
            {
                continue;
            }
            cur[c] = cur[c - 1] + pre[c];
            // cur[c] %= 10000;
            if (c * 2 == r)
            {
                cout << c << "\t" << cur[c] << "\t";
                C(3 * c, c);
            }
        }
        pre.swap(cur);
    }
    return 0;
}

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
