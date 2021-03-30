#include<bits/stdc++.h>
using namespace std;
// 1.1
string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int cnt = 0, carry = 0;
    string ans;
    while (cnt < num1.size() || cnt < num2.size())
    {
        char a = cnt < num1.size() ? num1[cnt] : '0';
        char b = cnt < num2.size() ? num2[cnt] : '0';
        char c = a - '0' + b + carry;
        carry = 0;
        if (c > '9')
        {
            carry = 1;
            c -= 10;
        }
        ans += c;
        cnt++;
    }
    if (carry == 1)
    {
        ans += '1';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    cout << addStrings(num1, num2) << endl;
}