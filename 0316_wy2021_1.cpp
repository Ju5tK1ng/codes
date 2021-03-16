#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	a[0] = 1;
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	a[4] = 7;
	a[5] = 13;
	for (int i = 6; i < 100001; i++)
	{
		a[i] = (a[i-1] + a[i-2] + a[i-3]) % 10007;
	}
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}
