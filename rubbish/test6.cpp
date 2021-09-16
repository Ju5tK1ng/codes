#include <bits/stdc++.h>
using namespace std;

struct A
{
    int i;
    char* c;
    char str[256];
};

int main()
{
    A a[10];
    cout << (char*)(a[2].str + 256) - (char*)(a) << endl;
    char c[2];
    cout << sizeof(c) << " " << strlen(c) << endl;
    vector<int> v(10);
    iota(v.begin(), v.end(), 0);
    auto ite = v.begin();
    auto ite3 = ite + 3;
    cout << (ite < ite3) << endl;
    return 0;
}
