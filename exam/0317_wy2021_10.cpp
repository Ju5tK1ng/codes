#include<bits/stdc++.h>
using namespace std;
int dp[1010][10010], w[1010], p[1010];
int main()
{
	int v, k, t, n = 0;
	cin >> v;
	getchar();
	char c;
	while (c = getchar())
	{
		if (c != ' ' && c != '\n')
		{
			t = t * 10 + (c - '0');
		}
		else if (c == ' ')
		{
			w[n++] = t;
			t = 0;
		}
		else
		{
			w[n++] = t;
			t = 0;
			break;
		}
	}
	n = 0;
	while (c = getchar())
	{
		if (c != ' ' && c != '\n')
		{
			t = t * 10 + (c - '0');
		}
		else if (c == ' ')
		{
			p[n++] = t;
			t = 0;
		}
		else
		{
			p[n++] = t;
			t = 0;
			break;
		}
	}
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = v; j >= 0; j--)
		{
			if (j >= w[i])
			{
				for (int kk = k; kk >= 1; kk--)
				{
					dp[j][kk] = max(dp[j][kk], dp[j - w[i]][kk - 1] + p[i]);
				}
			}
		}
	}
	cout << dp[v][k] << endl;
	return 0;
}
