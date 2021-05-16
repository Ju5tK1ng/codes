#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        version1 += '.';
        version2 += '.';
        istringstream s1(version1);
        istringstream s2(version2);
        int n1 = 0, n2 = 0;
        char c;
        while (s1 || s2)
        {
            s1 >> n1 >> c;
            s2 >> n2 >> c;
            if (n1 > n2)
            {
                return 1;
            }
            else if (n1 < n2)
            {
                return -1;
            }
            n1 = 0;
            n2 = 0;
        }
        return 0;
    }
};

// 数字过大时直接比较字符串，去掉前导0，先比较长度，若等于则逐位比较