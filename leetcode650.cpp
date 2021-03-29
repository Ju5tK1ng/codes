#include<bits/stdc++.h>
using namespace std;
int minSteps(int n) {
    int a[n + 1];
    a[1] = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            a[j] = j / i + a[i];
        }
    }
    return a[n];
}
// 2.0
// int minSteps(int n) {
//     int dp[n + 1];
//     dp[1] = 0;
//     int h = sqrt(n);
//     for (int i = 2; i <= n; ++i) {
//         dp[i] = i;
//         for (int j = 2; j <= h; ++j) {
//             if (i % j == 0) {
//                 dp[i] = dp[j] + dp[i/j];
//                 break;
//             }
//         }
//     }
//     return dp[n];
// }
int main()
{
    int n;
    cin >> n;
    cout << minSteps(n);
    return 0;
}