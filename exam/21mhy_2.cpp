#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e10;
int main()
{
    long long t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long l = 1, r = MAXN;
        while (true)
        {
            long long m = l + (r - l) / 2;
            if ((m - 1) * m / 2 >= n)
            {
                r = m;
            }
            else if ((m + 1) * m / 2 < n)
            {
                l = m;
            }
            else
            {
                cout << m << endl;
                break;
            }
        }
    }
    return 0;
}
