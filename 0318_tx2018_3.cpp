#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, ans = 0;
	cin >> n >> m;
	int left = 1, right = m;
	while (left < right)
	{
		int mid = (left + right + 1) / 2;
		int t = mid;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += t;
			t = (t + 1) / 2;
		}
		if (sum == m)
		{
			ans = mid;
			break;
		}
		else if (sum < m)
		{
			left = mid;
		}
		else
		{
			right = mid - 1;
		}
		ans = right;
	}
	cout << ans << endl;
}
