#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=40040;
int dp[maxn];
int main(){
	int n,p;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&p);
		int ans=0,x;
		for(int i=1;i<=p;i++) dp[i]=maxn;
		for(int i=1;i<=p;i++){
			scanf("%d",&x);
			int k=lower_bound(dp+1,dp+p,x)-dp;
			dp[k]=x;
			ans=max(ans,k);
		}
		printf("%d\n",ans);
	}
}
