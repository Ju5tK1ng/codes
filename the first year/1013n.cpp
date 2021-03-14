#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n, all;
	while (cin >> n) {
		all = 1;
		for (int i = 1;i < n;i++) {
			all = (all + 1) * 2;
		}
		cout << all << endl;
	}
	return 0;
}