#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, x[4], y[4];
	cin >> t;
	while(t--)
	{
		int d = 1;
		for (int i = 0; i < 4; i++)
		{
			cin >> x[i];
		}
		for (int i = 0; i < 4; i++)
		{
			cin >> y[i];
			if (i > 1 && (x[0] - x[i]) * (x[0] - x[i]) + (y[0] - y[i]) * (y[0] - y[i]) >
						 (x[0] - x[d]) * (x[0] - x[d]) + (y[0] - y[d]) * (y[0] - y[d]))
			{
				d = i;
			}
		}
		int tx = x[d], ty = y[d];
		x[d] = x[2], y[d] = y[2];
		x[2] = tx, y[2] = ty;
		if ((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]) ==
			(x[0] - x[3]) * (x[0] - x[3]) + (y[0] - y[3]) * (y[0] - y[3]) &&
			(x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]) ==
			(x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
