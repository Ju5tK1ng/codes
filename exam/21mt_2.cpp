#include <bits/stdc++.h>
using namespace std;
int T, n, m, v;
int a[25], b[25];

bool ok(int i)
{
    int cnt = 0;
    while (i)
    {
        cnt += i & 1;
        i = i >> 1;
    }
    return cnt <= m;
}

int main()
{
    cin >> T;
    bitset<5> binary;
    while (T--)
    {
        cin >> n >> m >> v;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i] * a[i] * a[i];
        }
        bool find = false;
        for (int i = 0; i < (1 << n); i++)
        {
            if (ok(i))
            {
                binary = i;
                // cout << binary << '\t';
                int sum = 0;
                for (int j = 0; j < n; j++)
                {
                    if ((1 << j) & i)
                    {
                        sum += b[j];
                    }
                    else
                    {
                        sum += a[j];
                    }
                }
                // cout << sum << endl;
                if (sum == v)
                {
                    find = true;
                    break;
                }
            }
        }
        if (find)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
