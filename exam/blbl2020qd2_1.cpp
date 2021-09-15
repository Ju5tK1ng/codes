#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r1, i1, r2, i2;
    char c;
    string s;
    getline(cin, s);
    istringstream ss1(s);
    ss1 >> r1 >> c >> i1 >> c;
    getline(cin, s);
    istringstream ss2(s);
    ss2 >> r2 >> c >> i2 >> c;
    cout << r1 * r2 - i1 * i2 << "+" << r1 * i2 + r2 * i1 << "i" << endl;
    return 0;
}
