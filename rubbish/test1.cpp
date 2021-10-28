#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    a += b += c;
    cout << a << endl << b << endl << c << endl;
    cout << (int)'0' << " " << ('0' ^ 1) << " " << ('1' ^ 1) << endl;
    string s;
    s.push_back(49);
    cout << s << endl;
    cout << 4 * 6 / __gcd(4,6) << endl;
    return 0;
}
