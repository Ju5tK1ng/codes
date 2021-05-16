#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[1010];
int dp[2][40];
int main(){
	int t,w,now,pre=1,cnt=1;
	cin>>t>>w;
	for(int i=0;i<t;i++){
		scanf("%d",&now);
		if(now==pre) a[cnt]++;
		else a[++cnt]=1;
		pre=now;
	}
	int p=1;
	for(int i=1;i<=cnt;i++){
		p=1-p;
		dp[p][0]=dp[1-p][0]+a[i]*(i%2);
		for(int j=1;j<=w;j++){
			dp[p][j]=max(dp[1-p][j-1],dp[1-p][j])+a[i]*((i+j)%2);
		}
	}
	sort(dp[p],dp[p]+w+1);
	cout<<dp[p][w]<<endl;
	return 0;
}
