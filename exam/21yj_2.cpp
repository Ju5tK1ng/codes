#include <bits/stdc++.h>
using namespace std;

void C(int n) {
    vector<int> v;
    vector<int> s;
    size_t ans = 1;
    for (int i = 2 * n + 2; i <= 3 * n; i++)
    {
        v.push_back(i);
    }
    for (int i = 2; i <= n; i++)
    {
        s.push_back(i);
    }
    for (int& i : v) {
        vector<int> erase;
        vector<int> insert;
        for (int& j : s)
        {
            int gcd = __gcd(i, j);
            if (gcd != 1)
            {
                i /= gcd;
                j /= gcd;
            }
        }
        ans = (ans * i) % 10000;
    }
    cout << ans << "\t" << s.size() << endl;
}

int main()
{
    int row = 500, col = 250;
    vector<size_t> pre(row, 0), cur(col, 0);
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
            cur[c] %= 10000;
            if (c * 2 == r)
            {
                cout << c << "\t" << cur[c] << "\t";
                C(c);
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
