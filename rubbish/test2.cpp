#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 0b10101010;
    for (int i = a; i; i = (i - 1) & a)
    {
        cout << bitset<8>(i) << endl;
    }
    cout << "-------------------" << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << bitset<8>(i & -i) << endl;
    }
    cout << __cplusplus <<endl;
    return 0;
}
