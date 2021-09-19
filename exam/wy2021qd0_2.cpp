#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a, b, c, d, e;
	cin>>a>>b>>c>>d>>e;
	long long ans = (a + b + c + d + e) / 3;
	long long lans, mans, rans;
	if (ans < a)
	{
		ans = (b + c + d + e) / 2;
		if (ans < b + c)
		{
			cout << d + e;
		}
		else if (ans < b + c + d)
		{
			cout << ans;
		}
		else
		{
			cout << b + c + d;
		}
	}
	else if (ans < e)
	{
		ans = (a + b + c + d) / 2;
		if (ans < c + d)
		{
			cout << a + b;
		}
		else if (ans < b + c + d)
		{
			cout << ans;
		}
		else
		{
			cout << b + c + d;
		}
	}
	else if (ans < a + b && ans < d + e)
	{
		cout<<ans;
	}
	else if (ans < a + b && ans < c + d + e)
	{
		cout<<d + e;
	}
	else if (ans < a + b + c && ans < d + e)
	{
		cout<<a + b;
	}
	else
	{
		cout<<(a + b, d + e);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long e, em, m, mh, h;
    cin >> e >> em >> m >> mh >> h;
    long long ans = min(e + em, mh + h);
    ans = min(ans, em + m + mh);
    ans = min(ans, (e + em + m + mh + h) / 3);
    cout << ans << endl;
    return 0;
}
