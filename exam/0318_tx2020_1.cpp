#include<bits/stdc++.h>
using namespace std;
string compress(string str)
{
	string s;
	int a = 0, b = 0, c = 0, n = 0;
	while (a < str.length())
	{
		while (str[a] != '[' && a < str.length())
		{
			s += str[a];
			a++;
		}
		if(str[a] == '[')
		{
			a++;
			c++;
		}
		n = 0;
		while (str[a] != '|' && a < str.length())
		{
			n = n * 10 + (str[a] - '0');
			a++;
		}
		if (str[a] == '|')
		{
			a++;
		}
		b = -1;
		while (c != 0)
		{
			b++;
			if (str[a + b] == '[')
			{
				c++;
			}
			else if (str[a + b] == ']')
			{
				c--;
			}
		}
		for (int i = 0; i < n; i++)
		{
			s += compress(str.substr(a, b));
		}
		a = a + b + 1;
	}
	return s;
}

int main()
{
	string str;
	cin >> str;
	cout << compress(str) << endl;;
	return 0;
}
