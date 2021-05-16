#include<bits/stdc++.h>
using namespace std;
map<long long, long long> m;

long long solve(long long n){
    if(m.count(n)) return m[n];
    long long cnt = 0;
    if(n % 2 == 0) cnt = solve(n >> 1) + solve(((n - 2) >> 1));
    else cnt = solve(n >> 1);
    m[n] = cnt;
    return cnt;
}

int main(){
    m[0] = 1; m[1] = 1;
    long long n;
	cin >> n;
    cout << solve(n) << endl;
    return 0;
}
