#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	double x1, y1, x2, y2, x;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		x = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		printf("%.2lf\n", x);
	}
	return 0;
}