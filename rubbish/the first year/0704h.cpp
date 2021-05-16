#include<iostream>
#include<cstdio>
using namespace std;
long long dp[1010][110],dp2[1010][110],inf=1;
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<18;i++) inf*=10;
	for(int i=0;i<=k;i++) dp2[0][i]=1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(j<i){
				dp[j][i]=dp[j][i-1];
				dp2[j][i]=dp2[j][i-1];
			}else{
				dp[j][i]=dp[j][i-1]+dp[j-i][i]+(dp2[j][i-1]+dp2[j-i][i])/inf;
				dp2[j][i]=(dp2[j][i-1]+dp2[j-i][i])%inf;
			}
		}
	}
	if(dp[n][k]) cout<<dp[n][k];
	cout<<dp2[n][k]<<endl;
	return 0;
}
