#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	int n;
	while(cin>>n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a+n);
		int ans1 = 0, ans2 = 0;
		int b = 0, c = n - 2;
		while (a[b] == a[0])
		{
			b++;
		}
		while (a[n - 1] == a[c])
		{
			c--;
		}
		ans2 = b * (n - 1 - c);
		int minN = a[n - 1] - a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i] - a[i - 1] < minN)
			{
				minN = a[i] - a[i - 1];
			}
		}
		if (minN == 0)
		{
			for (int i = 1; i < n; i++)
			{
				for (int j = 0; j < i; j++)
				{
					if (a[i] == a[j])
					{
						ans1++;
					}
				}
			}
		}
		else
		{
			for (int i = 1; i < n; i++)
			{
				if (a[i] - a[i - 1] == minN)
				{
					ans1++;
				}
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
