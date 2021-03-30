#include<bits/stdc++.h>
using namespace std;
bool isPowerOfThree(int n) {
    return fmod(log10(n) / log10(3), 1) == 0;
}
// 2.0
// bool isPowerOfThree(int n) {
//     return n > 0 && 1162261467 % n == 0;
// }
int main()
{
    int n;
    cin >> n;
    cout << isPowerOfThree(n) << endl;
    return 0;
}