#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int search(int i)
{
	if (i < 10000000) return a[i];
	int t3, t2, t1 = 2e9;
	if (i % 3 == 0)
	{
		t3 = search(i / 3) + 1;
	}
	if (i % 2 == 0)
	{
		t2 = search(i / 2) + 1;
	}
	if (i % 3 != 0 || i % 2 != 0)
	{
		t1 = search(i - 1) + 1;
	}
	return min(t3, min(t2, t1));
}
int main()
{
	a[1] = 1;
	a[2] = 2;
	a[3] = 2;
	a[4] = 3;
	a[5] = 4;
	a[6] = 3;
	for (int i = 7; i < 10000000; i++)
	{
		a[i] = 2e9;
		if (i % 3 == 0)
		{
			a[i] = min(a[i], a[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			a[i] = min(a[i], a[i / 2] + 1);
		}
		a[i] = min(a[i], a[i - 1] + 1);
	}
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << search(n) << endl;
	}
	return 0;
}
