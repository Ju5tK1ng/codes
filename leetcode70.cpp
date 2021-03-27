#include<bits/stdc++.h>
using namespace std;
// 1.1
int climbStairs(int n) {
    if (n == 1)
    {
        return 1;
    }
    int a = 1, b = 2, c;
    n -= 2;
    while (n--)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main()
{
    int n;
    cin >> n;
    cout <<climbStairs(n) << endl;
    return 0;
}