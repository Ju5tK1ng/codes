#include<bits/stdc++.h>
using namespace std;
int c[9], d[9];
int pw[10];
int dp[1 << 20 + 1];
int maxHappyGroups(int b, vector<int>& a) {
    memset(c, 0, sizeof(int) * b);
    for(auto i : a) c[i % b]++;
    int mx = 1;
    pw[0] = 1;
    for(int i = 0; i < b; i++) {
        mx *= (c[i] + 1);   // c[i] + 1表示可以取0 ~ c[i]个数
        pw[i + 1] = pw[i] * (c[i] + 1);
    }
    dp[0] = 1;
    int ans = 0;
    // i可以理解为一个数，第一低位是c[0] + 1进制，第二低位是c[1] + 1进制，以此类推
    // mx表示所有可能的组合一共有多少个
    // d[j]表示第j + 1低位的数，意义为模b余j的数取多少个
    // dp[i]表示当前组合的最大值
    // s == 0表示当前组合是b的倍数，这样当前组合加上任意一个数组成的新组合都可以+1
    for(int i = 1; i < mx; i++) {
        int x = i;
        dp[i] = 0;
        int s = 0;
        for(int j = 0; j < b; j++) {
            d[j] = x % (c[j] + 1);
            x /= (c[j] + 1);
            if(d[j] > 0) {
                dp[i] = max(dp[i], dp[i - pw[j]]);
            }
            s = (s + d[j] * j) % b;
        }
        ans = max(ans, dp[i]);
        if(s == 0) {
            dp[i]++;
        }
    }
    return ans;
}