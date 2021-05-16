#include<bits/stdc++.h>
using namespace std;
vector<string> getGray(int n) {
	vector<string> s;
	if (n < 1) return s;
    for (int i = 0; i < (1 << (n - 1)); i++)
    {
    	s.push_back("0");
	}
	for (int i = 0; i < (1 << (n - 1)); i++)
    {
    	s.push_back("1");
	}
	vector<string> s2 = getGray(n - 1);
	if (!s2.empty())
	{
		for (int i = 0; i < (1 << (n - 1)); i++)
		{
			s[i] += s2[i];
			s[(1 << n) - 1 - i] += s2[i];
		}
	}
	return s;
}
int main()
{
	int n;
	cin >> n;
	vector<string> s = getGray(n);
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	return 0;
}
