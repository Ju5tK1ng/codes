#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, ans = 1, cnt = 1;
	cin >> n >> m;
	m -= ans;
	while (cnt + m >= n && m >= 0)
	{
		ans *= 2;
		m -= ans;
		cnt++;
	}
	cnt--;
	m += ans;
	ans /= 2;
	int t = 1;
	m = m + cnt - n;
	cout << m << endl << cnt << endl;
	if (m >= cnt)
	{
		m -= cnt;
		ans += 1;
		cnt--;
	}
	while (m >= cnt && cnt > 0)
	{
		for (int i = 0; i < t; i++)
		{
			if (m >= cnt)
			{
				m -= cnt;
				ans += 1;
				break;
			}
		}
		cnt--;
		t *= 2;
		cout << m << ' ' << ans << endl ;
	}
	cout << ans << endl;
	return 0;
}
