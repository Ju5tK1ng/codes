#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, left = -90, right = 90;
	cin >> n;
	for (int i = 0; i < 6; i++)
	{
		int mid = (left + right) / 2;
		if (n < mid)
		{
			cout << 0;
			right = mid;
		}
		else
		{
			cout << 1;
			left = mid;
		}
	}
	cout << endl;
	return 0;
}
