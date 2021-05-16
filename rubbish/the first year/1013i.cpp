#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double n, f, z, l, x;
	while (1) {
		f = 0;
		z = 0;
		l = 0;
		cin >> n;
		if (n == 0) return 0;
		for (int i = 0;i < n;i++) {
			cin >> x;
			if (x > 0) {
				z++;
			}
			else if (x < 0) {
				f++;
			}
			else {
				l++;
			}
		}
		cout << f << " " << l << " " << z << endl;
	}
	return 0;
}