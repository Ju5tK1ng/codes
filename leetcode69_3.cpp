#include<bits/stdc++.h>
using namespace std;
// 3.0
int mySqrt(int x) {
    long ans = x;
    while (ans * ans > x)
    {
        ans = (ans + x / ans) / 2;
    }
    return ans;
}
int main()
{
    int x;
    cin >> x;
    cout << mySqrt(x) << endl;
    return 0;
}