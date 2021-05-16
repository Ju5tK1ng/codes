#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int l = s.length();
	int a, b;
	for (a = l / 2; a < l; a++)
	{
		int t = 1;
		while (t <= l - 1 - a && s[a + t] == s[a - t])
		{
			t++;
		}
		if (t > l - 1 - a)
		{
			break;
		}
	}
	for (b = (l + 1) / 2 - 1; b < l; b++)
	{
		int t = 0;
		while (t <= l - 2 - b && s[b + 1 + t] == s[b - t])
		{
			t++;
		}
		if (t > l - 2 - b)
		{
			break;
		}
	}
	if (a * 2 + 1 < b * 2 + 2)
	{
		for (int i = 0; i < a; i++)
		{
			cout << s[i];
		}
		for (int i = a; i >= 0; i--)
		{
			cout << s[i];
		}
	}
	else
	{
		for (int i = 0; i <= b; i++)
		{
			cout << s[i];
		}
		for (int i = b; i >= 0; i--)
		{
			cout << s[i];
		}
	}
	return 0;
}
