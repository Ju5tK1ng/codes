#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    int n, minindex = 0, maxindex = 0;
	bool pos = true;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	if (i != 0 && a[i] < a[i - 1])
    	{
    		pos = false;
		}
		if (a[i] < a[minindex])
		{
			minindex = i;
		}
		if (a[i] > a[maxindex])
		{
			maxindex = i;
		}
	}
	if (pos)
	{
		cout << 0 << endl;
	}
	else if (minindex == n - 1 && maxindex == 0)
	{
		cout << 3 << endl;
	}
	else if (minindex == 0 || maxindex == n - 1)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 2 << endl;
	}
    return 0;
}
