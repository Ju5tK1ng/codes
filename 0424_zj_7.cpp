#include<bits/stdc++.h>
using namespace std;
double n, e, cnt = 1, t, ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        cnt *= 2;
        e = e + t / cnt;
        ans = max(ans, ceil(e));
    }
    cout << (int)ans << endl;
    return 0;
}