#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n, i, a[60];
	while (cin >> n) {
		if (n == 0) return 0;
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		for (i = 3;i < n;i++) {
			a[i] = a[i - 1] + a[i - 3];
		}
		cout << a[n - 1] << endl;
	}
	return 0;
}