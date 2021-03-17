#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	string s;
	cin >> s;
	a[0] = 1;
	a[1] = a[0];
	if (s[0] == '1')
	{
		a[1] += 1;
	}
	a[2] = a[1];
	if (s[1] == '1')
	{
		a[2] += a[0];
	}
	if (s[0] == '1')
	{
		a[2] += 1;
	}
	for (int i = 3; i < s.length(); i++)
	{
		a[i] = a[i - 1];
		if (s[i - 1] == '1')
		{
			a[i] += a[i - 2];
		}
		if (s[i - 2] == '1')
		{
			a[i] += a[i - 3];
		}
	}
	cout << a[s.length() - 1] << endl;
	return 0;
} 
