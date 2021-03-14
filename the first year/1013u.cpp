#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n, i, j, x, a[110], b[110];
	while (cin >> n) {
		if (n == 0) return 0;
		for (i = 0;i < n;i++) {
			cin >> x;
			a[i] = x;
			if (x < 0) {
				b[i] = -x;
			}
			else {
				b[i] = x;
			}
			for (j = i;j > 0;j--) {
				if (b[j] > b[j - 1]) {
					swap(b[j], b[j - 1]);
					swap(a[j], a[j - 1]);
				}
			}
		}
		for (i = 0;i < n;i++) {
			if (i > 0) {
				cout << " ";
			}
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}