#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main()
{
	int n, t = 1;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		ans += a[i] * t;
		t = -t; 
	}
	cout << ans << endl;
	return 0;
}
