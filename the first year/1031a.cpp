#include<iostream>
#include<cstring>
using namespace std;
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = { "no","js","hw","ds" };
char r(char ch)
{
	if (isalpha(ch)) return rev[ch - 'A'];
	return rev[ch - '0' + 25];
}
int main()
{
	char str[30];
	cin >> str;
	int j = 1, h = 1;
	for (int i = 0; i < strlen(str) / 2; i++) {
		if (str[i] != str[strlen(str) - 1 - i]) h = 0;
		if (r(str[i]) != str[strlen(str) - 1 - i]) j = 0;
	}
	cout << msg[h * 2 + j];
	return 0;
}
