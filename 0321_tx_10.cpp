#include<bits/stdc++.h>
using namespace std;
int w[110];
int main()
{
	int n, ans = 0;;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		sort(w + i, w + n);
		ans += w[i] * w[i + 1];
		w[i + 1] += w[i];
	}
	cout << ans << endl;
	return 0;
}
