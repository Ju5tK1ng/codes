#include<bits/stdc++.h>
using namespace std;
int a[1000010], b[1000010];
int main()
{
	int m, n = 0, t = 0;
	cin >> m;
	getchar();
	char c;
	while (c = getchar())
	{
		if (c != ' ' && c != '\n')
		{
			t = t * 10 + (c - '0');
		}
		else if (c == ' ')
		{
			a[n++] = t;
			t = 0;
		}
		else
		{
			a[n++] = t;
			break;
		}
	}
	b[0] = m;
	if (b[0] - 2 >= 0)
	{
		b[1] = b[0] - 2 + a[0];
	}
	else
	{
		b[1] = -1;
	}
//	cout << b[0] << endl << b[1] << endl;
	for (int i = 2; i <= n; i++)
	{
		if (b[i - 1] - 2 >= 0 && b[i - 2] - 3 >= 0)
		{
			b[i] = max(b[i - 1] - 2 + a[i - 1], b[i - 2] - 3 + a[i - 1]);
		}
		else if (b[i - 1] - 2 >= 0)
		{
			b[i] = b[i - 1] - 2 + a[i - 1];
		}
		else if (b[i - 2] - 3 >= 0)
		{
			b[i] = b[i - 2] - 3 + a[i - 1];
		}
		else
		{
			b[i] = -1;
		}
//		cout << b[i] << endl;
	}
	sort(b + 1, b + n + 1);
	cout << b[n] << endl;
	return 0;
}
