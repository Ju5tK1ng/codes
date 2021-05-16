#include<bits/stdc++.h>
using namespace std;
int numSquares(int n) {
    vector<int> dp(n + 1, 0x3f3f3f3f);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}
// 2.0
// bool check(int x){
//     int r=sqrt(x);
//     return r*r==x;
// }
// int numSquares(int n) {
//     if(check(n)) return 1;
//     while(n%4==0) n/=4;
//     if(n%8==7)return 4;
//     for(int a=1;a<=n/a;a++){
//         if(check(n-a*a)) return 2;
//     }
//     return 3;
// }
int main()
{
    int n;
    cin >> n;
    cout << numSquares(n) << endl;
    return 0;
}