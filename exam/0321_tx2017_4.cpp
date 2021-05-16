#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i == 3)
		{
			ans += (s[i] - 'a') + 1;
		}
		else if (i == 2)
		{
			ans += (s[i] - 'a') * 25 + (s[i] - 'a') + 1;
		}
		else if (i == 1)
		{
			ans += (s[i] - 'a') * 25 * 25 + (s[i] - 'a') * 25 + (s[i] - 'a') + 1;
		}
		else if (i == 0)
		{
			ans += (s[i] - 'a') * 25 * 25 * 25 + (s[i] - 'a') * 25 * 25 + (s[i] - 'a') * 25 + (s[i] - 'a') + 1;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
