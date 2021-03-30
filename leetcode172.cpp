#include<bits/stdc++.h>
using namespace std;
int trailingZeroes(int n) {
    if (n == 0)
    {
        return 0;
    }
    return n / 5 + trailingZeroes(n / 5);
}
int main()
{
    int num;
    cin >> num;
    cout << trailingZeroes(num) << endl;
}