#include <bits/stdc++.h>
using namespace std;
void Print(int a, int b, int c)
{
    int* p = &b;
    cout << &a << '\t' << &b << '\t' << &c << endl;
    cout << p << '\t' << p - 1 << endl;
    cout << *(p - 2) << endl;
}

int main()
{
    Print(1, 2, 3);
    return 0;
}
