#include<bits/stdc++.h>
using namespace std;
// 2.0
int reinitializePermutation(int n) {
    int start = 1, cur = 1, ans = 0;
    while (1)
    {
        if (cur < n / 2)
        {
            cur *= 2;
        }
        else
        {
            cur = (cur - n / 2) * 2 + 1;
        }
        ans++;
        if (cur == start)
        {
            break;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << reinitializePermutation(n) << endl;
    return 0;
}