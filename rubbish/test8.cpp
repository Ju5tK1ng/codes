#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num = 100;
    char cs[20];
    itoa(num, cs, 8);
    string str(cs);
    num = strtol("1111", nullptr, 2);
    cout << cs << endl;
    cout << str << endl;
    cout << num << endl;
    return 0;
}
