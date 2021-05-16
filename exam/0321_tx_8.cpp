#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a, b, A, B, t = 1 << 30, ans = 30;
	cin >> a >> b >> A >> B;
	if (a > A || b > B)
	{
		cout << -1 << endl;
		return 0;
	}
	while (t > 1 && (a * t > A || b * t > B))
	{
		t /= 2;
		ans--;
	}
	a *= t;
	b *= t;
	A -= a;
	cout << A << endl;
	while (t)
	{
		int times = A / t;
		b += times * t;
		A = A % t;
		t = t / 2;
		if (times > 0)
		{
			ans++;
		}
	}
	if (b == B)
	{
		cout << ans << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}
