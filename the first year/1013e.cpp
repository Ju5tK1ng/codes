#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	while (cin >> t) {
		if (t < 0) {
			cout << "Score is error!\n";
		}
		else if (t < 60) {
			cout << "E\n";
		}
		else if (t < 70) {
			cout << "D\n";
		}
		else if (t < 80) {
			cout << "C\n";
		}
		else if (t < 90) {
			cout << "B\n";
		}
		else if (t <= 100) {
			cout << "A\n";
		}
		else {
			cout << "Score is error!\n";
		}
	}
	return 0;
}