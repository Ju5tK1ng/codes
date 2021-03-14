#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int x, y, n, ok;
	while (1) {
		cin >> x >> y;
		if (x == 0 && y == 0) return 0;
		ok = 1;
		for (int i = x;i <= y;i++) {
			n = i * i + i + 41;
			for (int j = 2;j < n;j++) {
				if (n%j == 0) {
					ok = 0;
				}
			}
		}
		if (ok) {
			cout << "OK" << endl;
		}
		else {
			cout << "Sorry" << endl;
		}
	}
	return 0;
}