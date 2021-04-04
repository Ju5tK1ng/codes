#include<bits/stdc++.h>
using namespace std;
bool vis[200005];
int countDifferentSubsequenceGCDs(vector<int>& nums) {
    memset(vis, false, sizeof(vis));
    for (int x: nums) vis[x] = true;
    int ans = 0;
    for (int i = 1; i <= 200000; ++i){
        int fst = 0;
        for (int j = i; j <= 200000; j += i){
            if (vis[j]) {
                fst = __gcd(fst, j);
            }
        }
        if (fst == i) ++ans;
    }
    return ans;
}