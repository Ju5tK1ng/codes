#include<bits/stdc++.h>
using namespace std;
void calNext(string& needle, int next[])
{
    for (int i = 1, p = -1; i < needle.size(); i++)
    {
        while (p > -1 && needle[p + 1] != needle[i])
        {
            p = next[p];
        }
        if (needle[p + 1] == needle[i])
        {
            p++;
        }
        next[i] = p;
    }
}
int strStr(string haystack, string needle) {
    int n1 = haystack.size(), n2 = needle.size();
    if (n2 == 0)
    {
        return 0;
    }
    int next[n2];
    memset(next, -1, sizeof(next));
    calNext(needle, next);
    for (int i = 0, p = -1; i < n1; i++)
    {
        while (p > -1 && needle[p + 1] != haystack[i])
        {
            p = next[p];
        }
        if (needle[p + 1] == haystack[i])
        {
            p++;
        }
        if (p == n2 - 1)
        {
            return i - p;
        }
    }
    return -1;
}
int main()
{
    string haystack, needle;
    cin >> haystack >> needle;
    cout << strStr(haystack, needle) << endl;
    cout << (int)haystack.find(needle) << endl;;
    return 0;
}