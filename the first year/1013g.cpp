#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n, x, pro;
	while (cin >> n) {
		pro = 1;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x % 2 == 1) {
				pro *= x;
			}
		}
		cout << pro << endl;
	}
	return 0;
}