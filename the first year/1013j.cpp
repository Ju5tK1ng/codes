#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double n, m, sum;
	while (cin >> n) {
		sum = 0;
		cin >> m;
		for (int i = 0;i < m;i++) {
			sum += n;
			n = sqrt(n);
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}