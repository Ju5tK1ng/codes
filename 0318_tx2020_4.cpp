#include<bits/stdc++.h>
using namespace std;
int dp[100010][3], a[100010], b[100010], n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
		if (a[i])
		{
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		}
		if (b[i])
		{
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		}
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
	return 0;
}
