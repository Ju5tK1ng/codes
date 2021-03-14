#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int m, n, i, j, x, ma, a[100][100], b[100][100];
out:
	while (cin >> m >> n) {
		for (i = 0;i < m;i++) {
			for (j = 0;j < n;j++) {
				cin >> x;
				a[i][j] = x;
				if (x < 0) {
					x = -x;
				}
				b[i][j] = x;
			}
		}
		ma = a[0][0];
		for (i = 0;i < m;i++) {
			for (j = 0;j < n;j++) {
				ma = max(ma, b[i][j]);
			}
		}
		for (i = 0;i < m;i++) {
			for (j = 0;j < n;j++) {
				if (ma == b[i][j]) {
					cout << i + 1 << " " << j + 1 << " " << a[i][j] << endl;
					goto out;
				}
			}
		}
	}
	return 0;
}