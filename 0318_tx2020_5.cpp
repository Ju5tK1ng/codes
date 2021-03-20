#include<bits/stdc++.h>
using namespace std;
struct P
{
	int a, b;
}p[100010];
bool compare(const P &x, const P &y)
{
	if (x.a == y.a)
	{
		return x.b > y.b;
	}
	return x.a < y.a;
}
int main()
{
	int n, l, cnt = 0;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].a >> p[i].b;
	}
	sort(p, p + n, compare);
	int end = p[0].b, choose = 0;
	cnt++; 
	for (int i = 1; i < n; i++)
	{
		if (p[choose].b >= l)
		{
			end = p[choose].b;
			cnt++;
			break;
		}
		if (p[i].a > end)
		{
			end = p[choose].b;
			cnt++;
		}
		if (p[i].a <= end && p[i].b > p[choose].b)
		{
			choose = i;
			if (p[choose].b >= l)
			{
				end = p[choose].b;
				cnt++;
				break;
			}
		}
	}
	if (end < l)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << cnt << endl;
	}
	return 0;
}
