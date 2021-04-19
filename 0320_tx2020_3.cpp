// 0.0
#include<bits/stdc++.h>
using namespace std;
int a[100010], t[100010], temp;
long long cnt;
const int mod = 1e9 + 7;
void merge_sort(int a[], int x, int y, int t[])
{
	if (y - x > 1)
	{
		int m = x + (y - x) / 2;
		int p = x, q = m, i = x;
		merge_sort(a, x, m, t);
		merge_sort(a, m, y, t);
		while (p < m || q < y)
		{
			if (q >= y || (p < m && a[p] <= a[q]))
			{
				t[i++] = a[p++];
			}
			else
			{
				t[i++] = a[q++];
				cnt = (cnt + m - p) % mod;
			}
		}
		for (int i = x; i < y; i++)
		{
			a[i] = t[i];
		}
	}
}
int InversePairs(vector<int> data) {
        for (int i = 0; i < data.size(); i++)
        {
        	a[i] = data[i];
		}
		merge_sort(a, 0, data.size(), t);
		return cnt;
    }
int main()
{
	vector<int> data;
	while (cin >> temp)
	{
//		if (temp == -1) break;
		data.push_back(temp);
	}
	cout << InversePairs(data) << endl;
//	for (int i = 0; i < data.size(); i++)
//	{
//		cout << a[i];
//		if (i == data.size() - 1) cout << endl;
//		else cout << ' ';
//	}
	return 0;
}

// 1.0
#include<bits/stdc++.h>
using namespace std;
const int maxn = (1 << 20) + 10;
int a[maxn], b[maxn], t[maxn], q[maxn], n, m, temp;
long long rev[25], pos[25];
void merge_sort(int a[], int x, int y, int t[], int n, long long rev[])
{
	if (y - x > 1)
	{
		int m = x + (y - x) / 2;
		int p = x, q = m, i = x;
		merge_sort(a, x, m, t, n - 1, rev);
		merge_sort(a, m, y, t, n - 1, rev);
		while (p < m || q < y)
		{
			if (q >= y || (p < m && a[p] <= a[q]))
			{
				t[i++] = a[p++];
			}
			else
			{
				t[i++] = a[q++];
				rev[n] += m - p;
			}
		}
		for (int i = x; i < y; i++)
		{
			a[i] = t[i];
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < (1 << n); i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> q[i];
	}
	merge_sort(a, 0, 1 << n, t, n, rev);
	reverse(b, b + (1 << n));
	merge_sort(b, 0, 1 << n, t, n, pos);
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= q[i]; j++)
		{
			swap(rev[j], pos[j]);
		}
		long long ans = 0;
		for (int j = 1; j <= n; j++)
		{
			ans += rev[j];
		}
		cout << ans << endl;	
	}
	return 0;
}
