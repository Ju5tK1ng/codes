#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long dp[maxn][4];
string s;
int main(){
	cin>>s;
	int l=s.length();
	dp[1][0]=dp[1][1]=dp[2][0]=dp[2][2]=dp[3][0]=dp[3][3]=1;
	for(int i=2;i<=l;i++){
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1]+dp[i-1][0];
		dp[i][2]=dp[i-1][2]+dp[i-1][1];
		dp[i][3]=dp[i-1][3]+dp[i-1][2];
		if(s[i-1]==s[i-2]){
			dp[i][1]--;
			dp[i][2]-=dp[i-2][1];
			dp[i][3]-=dp[i-2][2];
		}
		else if(i>=3 && s[i-1]==s[i-3]){
			dp[i][2]--;
			dp[i][3]-=dp[i-3][1];
		}
		else if(i>=4 && s[i-1]==s[i-4]){
			dp[i][3]--;
		}
	}
	cout<<dp[l][0]+dp[l][1]+dp[l][2]+dp[l][3]<<endl;
	return 0;
}
