#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<string, int> m;
	string s;
	int n, ans = 0;
	cin >> n;
	int a = (n - 1) / 100;
	while (n--)
	{
		cin >> s;
		m[s]++;
	}
	for (map<string,int>::iterator it = m.begin(); it != m.end(); it++)
    {
    	if (it->second > a)
    	{
    		ans++;
		}
	}
	cout << ans << endl;
}
