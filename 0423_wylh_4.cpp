#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double ans = 0;
    cin >> n;
    while (n)
    {
        ans += 1.0 / n;
        n--;
    }
    printf("%.4f\n", ans);
    return 0;
}