#include<bits/stdc++.h>
using namespace std;
uint32_t reverseBits(uint32_t n) {
    unsigned int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        ans <<= 1;
        ans += n & 1;
        n >>= 1;
    }
    return ans;
}
int main()
{
    unsigned int n;
    cin >> n;
    cout << reverseBits(n);
    return 0;
}