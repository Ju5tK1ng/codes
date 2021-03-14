#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	char str[1000][50];
	int n, i, j, len, is;
	scanf("%d", &n);
	gets(str[0]);
	for (i = 0;i < n;i++) {
		is = 1;
		gets(str[i]);
		len = strlen(str[i]);
		if (str[i][0] >= '0'&&str[i][0] <= '9') {
			is = 0;
		}
		else {
			for (j = 0;j < len;j++) {
				if ((str[i][j] >= 'a'&&str[i][j] <= 'z') || (str[i][j] >= 'A'&&str[i][j] <= 'Z') || (str[i][j] >= '0'&&str[i][j] <= '9') || (str[i][j] == '_')) {
					continue;
				}
				else {
					is = 0;
					break;
				}
			}
		}
		if (is) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	return 0;
}