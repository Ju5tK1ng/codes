#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if ((a < 1 || a > 1024) || (b < 1 || b > 1024 ))
	{
		cout << -1 << endl;
	}
	else if (a == b)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}
