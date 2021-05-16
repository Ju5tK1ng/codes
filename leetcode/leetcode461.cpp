#include<bits/stdc++.h>
using namespace std;
int hammingDistance(int x, int y) {
    int diff = x ^ y, ans = 0;
    while (diff)
    {
        ans += diff & 1;
        diff >>= 1;
    }
    return ans;
}
int main()
{
    int x, y;
    cin >> x >> y;
    cout << hammingDistance(x, y) << endl;
    return 0;
}