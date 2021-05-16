#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int o, e, m, n, t;
	while (cin >> m >> n) {
		o = 0;
		e = 0;
		if (m > n) {
			t = m;
			m = n;
			n = t;
		}
		for (int i = m; i <= n; i++) {
			if (i % 2 == 0) {
				e += i * i;
			}
			else {
				o += i * i*i;
			}
		}
		cout << e << " " << o << endl;
	}
	return 0;
}