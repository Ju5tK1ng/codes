#include<bits/stdc++.h>
using namespace std;
int ans[1000][1000];
int main()
{
	int b;
	string s;
	while (cin>>s)
	{
		b = s.length();
		for (int i=0;i<=b;i++)
		{
			ans[i][0] = 0;
			ans[0][i] = 0;
		}
		for (int i=1;i<=b;i++)
		{
			for (int j=1;j<=b;j++)
			{
				if (s[i-1] == s[b-j])
				{
					ans[i][j] = ans[i-1][j-1] + 1;
				}
				else
				{
					ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
				}
			}
		}
		cout<<b-ans[b][b]<<endl;
	}
	return 0;
}
