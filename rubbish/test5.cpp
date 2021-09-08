#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 2;
    int& b = a;
    int* c;
    *c = b;
    b = 3;
    cout << a << b << *c << endl;
    return 0;
}
