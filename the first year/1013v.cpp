#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n, i, x, num;
	while (cin >> n) {
		num = 0;
		if (n == 0) return 0;
		for (i = 0;i < n;i++) {
			cin >> x;
			num += x / 100;
			x %= 100;
			num += x / 50;
			x %= 50;
			num += x / 10;
			x %= 10;
			num += x / 5;
			x %= 5;
			num += x / 2;
			x %= 2;
			num += x / 1;
		}
		cout << num << endl;
	}
	return 0;
}