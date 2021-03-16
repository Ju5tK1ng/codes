#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while (cin>>s)
	{
		int len = s.length();
		for (int i = len-1; i>=0; i--)
		{
			for (int j = i; j>=0; j--)
			{
				if (s[j] >= 'A' && s[j] <= 'Z')
				{
					char t = s[j];
					while (j < i)
					{
						s[j] = s[j+1];
						j++;
					}
					s[i] = t;
					break;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
