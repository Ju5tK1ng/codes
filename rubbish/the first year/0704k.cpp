#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=2010;
int n,a[maxn],b[maxn],dp[maxn][maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		int mi=dp[i-1][1];
		for(int j=1;j<=n;j++){
			mi=min(mi,dp[i-1][j]);
			dp[i][j]=abs(a[i]-b[j])+mi;
		}
	}
	int ans=dp[n][1];
	for(int i=2;i<=n;i++){
		ans=min(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}
