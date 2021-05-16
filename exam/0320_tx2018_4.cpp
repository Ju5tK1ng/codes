#include<bits/stdc++.h>
using namespace std;
long long dp[1010];
int k, a, x, b, y, s[210]; 
const int mod = 1e9 + 7; 
int main()
{
	cin >> k >> a >> x >> b >> y;
	for (int i = 0; i < x; i++)
	{
		s[i] = a;
	}
	for (int i = x; i < x + y; i++)
	{
		s[i] = b;
	}
	dp[0] = 1;
	for (int i = 0; i < x + y; i++)
	{
		for (int j = k; j >= s[i]; j--)
		{
			dp[j] = (dp[j] % mod + dp[j - s[i]] % mod) % mod;
		}
	}
	cout << dp[k] << endl;
	return 0;
}
