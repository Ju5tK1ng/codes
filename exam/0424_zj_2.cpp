#include<bits/stdc++.h>
using namespace std;
long long n, d, ans;
int b[1000010];
const int MOD = 99997867;
int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    long long i = 0, j = 2;
    for (; i < n - 2; i++)
    {
        for (; j < n && b[i] + d >= b[j]; j++);
        ans = (ans + (j - i - 1) * (j - i - 2) / 2) % MOD;
    }
    cout << ans << endl;
    return 0;
}