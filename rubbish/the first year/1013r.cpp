#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	char a[250];
	int n, cnt, i, j;
	cin >> n;
	gets(a);
	for (i = 0;i < n;i++) {
		gets(a);
		cnt = 0;
		for (j = 0;j < strlen(a);j++) {
			if ((a[j] - 48) >= 0 && (a[j] - 48) <= 9) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}