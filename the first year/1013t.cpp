#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n, m, i, k, x, a[110];
	while (cin >> n >> m) {
		if (n == 0 && m == 0) return 0;
		for (i = 0;i < n;i++) {
			cin >> x;
			a[i] = x;
		}
		for (i = 0;i < n;i++) {
			if (m < a[i]) {
				k = i;
				break;
			}
		}
		for (i = 0;i <= n;i++) {
			if (i > 0) {
				cout << " ";
			}
			if (i < k) {
				cout << a[i];
			}
			else if (i == k) {
				cout << m;
			}
			else {
				cout << a[i - 1];
			}
		}
		cout << endl;
	}
	return 0;
}