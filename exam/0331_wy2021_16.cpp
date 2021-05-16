#include<bits/stdc++.h>
using namespace std;
int a[100010];
int dp[100010];
int main()
{
    int C, cnt = 0;
    cin >> C;
    // string s;
    // getline(cin, s);
    // getline(cin, s);
    // istringstream ss(s);
    while(cin >> a[cnt])
    {
        cnt++;
    }
    for (int i = 0; i < cnt; i++)
    {
        for (int j = C; j >= a[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    cout << dp[C] << endl;
    return 0;
}