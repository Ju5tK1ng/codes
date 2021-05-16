#include<bits/stdc++.h>
using namespace std;
int n, ans;
int main()
{
    cin >> n;
    n = 1024 - n;
    for (int i = 0; i < 3; i++)
    {
        ans += n & 3;
        n = n >> 2;
    }
    ans += n;
    cout << ans << endl;
    return 0;
}