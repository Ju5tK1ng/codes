#include<bits/stdc++.h>
using namespace std;
char a[1010];
int cnt[1010];
int main()
{
	int n = 0, index = 0, d = 0;
	char c;
	while (c = getchar())
	{
		a[n++] = c;
		if (c == '1')
		{
			if (d != 0)
			{
				cnt[index++] = d;
				d = 0;
			}
		}
		else if (c == '\n')
		{
			if (d != 0)
			{
				cnt[index++] = d;
			}
			break;
		}
		else if (c == '0')
		{
			d++;
		}
	}
	if (a[0] == '0')
	{
		cnt[0] *= 2;
	}
	if (a[n - 2] == '0')
	{
		cnt[index - 1] *= 2;
	}
	sort(cnt, cnt + index);
	cout << (cnt[index - 1] - 1) / 2 + 1 << endl;
	return 0;
}
