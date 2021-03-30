#include<bits/stdc++.h>
using namespace std;
string convertToBase7(int num) {
    if (num == 0)
    {
        return "0";
    }
    string ans;
    string nagetive;
    if (num < 0)
    {
        nagetive = "-";
        num = -num;
    }
    while (num)
    {
        ans = to_string(num % 7) + ans;
        num /= 7;
    }
    ans = nagetive + ans;
    return ans;
}
int main()
{
    int num;
    cin >> num;
    cout << convertToBase7(num) << endl;
}