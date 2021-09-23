#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> t;
            ans += t;
        }
    }
    cout << ans << endl;
    return 0;
}
