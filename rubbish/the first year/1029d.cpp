#include<iostream>
#include<cstring>
using namespace std;
int a[3], b[3], t[3];
void numchange(int n, int j,int cnt);
int main()
{
	for (int i = 81; i < 343; i++) {
		numchange(i, 7,3);
		memcpy(a, t, sizeof(t));
		numchange(i, 9,3);
		memcpy(b, t, sizeof(t));
		if (a[0] == b[2] && a[1] == b[1] && a[2] == b[0]) {
			cout << i << endl
				<< a[0] << a[1] << a[2] << endl
				<< b[0] << b[1] << b[2] << endl;
		}
	}
	return 0;
}
void numchange(int n, int j,int cnt)
{
	if (n) {
		numchange(n / j, j,--cnt);
		t[cnt] = n % j;
	}
}
