#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	double ma, mi, sum, x;
	while (cin >> n) {
		ma = 0;
		mi = 100;
		sum = 0;
		for (int i = 0;i < n;i++) {
			cin >> x;
			ma = max(ma, x);
			mi = min(mi, x);
			sum += x;
		}
		printf("%.2lf\n", (sum - ma - mi) / (n - 2));
	}
	return 0;
}