#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n, mi, i, a[100];
	while (cin >> n) {
		if (n == 0) return 0;
		cin >> a[0];
		mi = a[0];
		for (i = 1;i < n;i++) {
			cin >> a[i];
			mi = min(mi, a[i]);
		}
		for (i = 0;i < n;i++) {
			if (a[i] == mi) {
				a[i] = a[0];
			}
		}
		a[0] = mi;
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