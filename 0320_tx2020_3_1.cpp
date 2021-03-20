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
