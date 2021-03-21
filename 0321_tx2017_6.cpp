#include<bits/stdc++.h>
using namespace std;
int p[1010], cnt = 0, ans = 0;
int main()
{
	p[cnt++] = 2;
	for (int i = 3; i < 1000; i++)
	{
		bool ok = true;
		for (int j = 0; j < cnt; j++)
		{
			if (i % p[j] == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			p[cnt++] = i;
		}
	}
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = i; j < cnt; j++)
		{
			if(p[i] + p[j] == n)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
