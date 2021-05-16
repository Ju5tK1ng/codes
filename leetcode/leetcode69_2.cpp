#include<bits/stdc++.h>
using namespace std;
// 2.0
int mySqrt(int x) {
    if (x == 0)
    {
        return 0;
    }
    int l = 1, r = x, m;
    while (r - l > 1)
    {
        m = l + (r - l) / 2;
        if (x / m == m)
        {
            return m;
        }
        else if (x / m > m)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return l;
}
int main()
{
    int x;
    cin >> x;
    cout << mySqrt(x) << endl;
    return 0;
}