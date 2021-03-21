#include<bits/stdc++.h>
using namespace std;
struct People
{
	long long x, y;
}p[100010];
bool cmp(People &a, People &b)
{
	if (a.x == b.x) return a.y > b.y;
	return a.x < b.x;
}
bool cmp2(People &a, People &b)
{
	return a.y < b.y;
}
int main()
{
	long long n, w;
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p + n, cmp2);
	for (int i = 0; i < n / 2; i++)
	{
		w -= p[i].x;
	}
	w /= (n / 2 + 1);
//	sort(p + n / 2, p + n, cmp2);
	if (w > p[n / 2].y)
	{
		cout << p[n / 2].y << endl;
	}
	else
	{
		cout << w << endl;
	}
	return 0;
}
