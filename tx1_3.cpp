#include<bits/stdc++.h>
using namespace std;
int b[100010];
int K[100000010];
int main()
{
	int n, m, t, q, p, k;
	cin >> n;
	vector<int> a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> t;
			a[i].push_back(t);
		}
	}
	cin >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			cin >> b[j];
			b[j]--;
		}
		cin >> k;
		memset(K, 0x3f, sizeof(K));
		for (int j = 0; j < p; j++)
		{
			for (int kk = 0; kk < a[b[j]].size(); kk++)
			{
				if (a[b[j]][kk] < K[1])
				{
					t = 1;
					K[t] = a[b[j]][kk];
					while (t * 2 <= k)
					{
						t *= 2;
						if (t + 1 <= k && K[t + 1] > K[t])
						{
							t = t + 1;
						}
						if (K[t / 2] < K[t])
						{
							swap(K[t / 2], K[t]);
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		cout << K[1] << endl;
	}
	return 0;
}
