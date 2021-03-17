#include<bits/stdc++.h>
using namespace std;
int l[10010][10010];
int main()
{
	vector<int> a[10010];
	int n, k, m, t1, t2, t3;
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				l[i][j] = 1e8;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> t1 >> t2 >> t3;
		l[t1][t2] = t3;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				l[i][j] = min(l[i][j], l[i][k] + l[k][j]);
			}
		}
	}
	int maxn = 0;
	for (int i = 1; i <= n; i++)
	{
		maxn = max(maxn, l[k][i]);
	}
	if (maxn == 1e8)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << maxn << endl;
	}
	return 0;
}
