#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n, m, i, j;
	double sum, t;
	cin >> m;
	for (i = 0;i < m;i++) {
		cin >> n;
		sum = 0;
		for (j = 1;j <= n;j++) {
			t = j;
			if (j % 2 == 1) {
				sum += 1 / t;
			}
			else {
				sum -= 1 / t;
			}
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}