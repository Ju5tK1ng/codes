#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<long long> nums;
    vector<char> chars;
    string s;
    long long a;
    char c;
    getline(cin, s);
    s = '+' + s;
    istringstream ss(s);
    while (ss >> c >> a)
    {
        if (c == '@')
        {
            nums.back() = nums.back() | (nums.back() + a);
        }
        else
        {
            nums.push_back(a);
            chars.push_back(c);
        }
        // cout << nums.back() << endl;
    }
    int i = 1;
    long long ans = 0;
    while (i < chars.size())
    {
        if (chars[i] == '+')
        {
            ans += nums[i - 1];
            i++;
        }
        else
        {
            while (i < chars.size() && chars[i] == 'x')
            {
                nums[i] *= nums[i - 1];
                i++;
            }
        }
    }
    cout << ans + nums.back() << endl;
    return 0;
}
