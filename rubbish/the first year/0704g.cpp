#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n[1010],dp[2][100010];
const int mod=1000000;
int main(){
	int t,a,s,b,f;
	cin>>t>>a>>s>>b;
	for(int i=0;i<a;i++){
		scanf("%d",&f);
		n[f]++;
	}
	int p=0;
	dp[0][0]=1;
	for(int i=1;i<=t;i++){
		p=1-p;
		memset(dp[p],0,sizeof(dp[p]));
		for(int j=0;j<=b;j++){
			for(int k=max(0,j-n[i]);k<=j;k++){
				dp[p][j]+=dp[1-p][k];
				dp[p][j]%=mod;
			}
		}
	}
	int ans=0;
	for(int i=s;i<=b;i++){
		ans+=dp[p][i];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
