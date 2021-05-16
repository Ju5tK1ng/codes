#include<bits/stdc++.h>
using namespace std;
struct twoint
{
	int a, b;
}machine[100010], task[100010];
int use[100010];
bool cmp1(twoint &x, twoint &y)
{
	if (x.b == y.b) return x.a < y.a;
	else return x.b < y.b;
}
bool cmp2(twoint &x, twoint &y)
{
	if (x.a == y.a) return x.b > y.b;
	else return x.a > y.a;
}
int main()
{
	int n, m, cnt = 0;
	long long profit = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> machine[i].a >> machine[i].b;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> task[i].a >> task[i].b;
	}
	sort(machine, machine + n, cmp1);
	sort(task, task + m, cmp2);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!use[j] && task[i].a <= machine[j].a && task[i].b <= machine[j].b)
			{
				use[j] = 1;
				cnt++;
				profit += task[i].a * 200 + task[i].b * 3;
				break;
			}
		}
	}
	cout << cnt << ' ' << profit << endl;
	return 0;
}
