#include<bits/stdc++.h>
using namespace std;
bool isPowerOfFour(int n) {
    return fmod(log10(n) / log10(4), 1) == 0;
}
// 2.0
// bool isPowerOfFour(int n) {
//     return n > 0 &&  !(n & (n - 1)) &&  (n & 1431655765);
// }
int main()
{
    int n;
    cin >> n;
    cout << isPowerOfFour(n) << endl;;
    return 0;
}