#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s, t;
	cin >> s >> t;
	int cnt = 0;
	for (int i = 0; i < t.length(); i++)
	{
		if (s[cnt] == t[i])
		{
			cnt++;
		}
		if (cnt == s.length())
		{
			break;
		}
	}
	if (cnt == s.length())
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}
