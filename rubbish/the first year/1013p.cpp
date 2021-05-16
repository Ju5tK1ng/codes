#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n, m, sum, a, t;
	while (cin >> n >> m) {
		t = n;
		a = 2;
		while (t != 0) {
			sum = 0;
			if (t >= m) {
				for (int j = 0;j < m;j++) {
					sum += a;
					a += 2;
				}
				if (t < n) {
					cout << " ";
				}
				cout << sum / m;
				t -= m;
			}
			else if (t > 0) {
				for (int j = 0;j < t;j++) {
					sum += a;
					a += 2;
				}
				if (t < n) {
					cout << " ";
				}
				cout << sum / t;
				t = 0;
			}
		}
		cout << endl;
	}
	return 0;
}