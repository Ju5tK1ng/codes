#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	double v, r, pi = 3.1415927;
	while (cin >> r) {
		v = 4.0 / 3 * pi*r*r*r;
		printf("%.3lf\n", v);
	}
	return 0;
}