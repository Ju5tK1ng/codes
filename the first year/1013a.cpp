#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a, b, c, d;
	while (1) {
		a = getchar();
		if (a == EOF) return 0;
		b = getchar();
		c = getchar();
		char d = getchar();
		if (a > b) {
			swap(a, b);
		}
		if (b > c) {
			swap(b, c);
		}
		if (a > b) {
			swap(a, b);
		}
		cout << a << " " << b << " " << c << endl;
	}
	return 0;
}