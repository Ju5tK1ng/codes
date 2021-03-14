#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
int n,dp[maxn][maxn];
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			cin>>dp[i][j];
		}
	}
	for(int l=1;l<n;l++){
		for(int i=0;i<n-l;i++){
			for(int j=i+1;j<i+l;j++){
				dp[i][i+l]=min(dp[i][i+l],dp[i][j]+dp[j][i+l]);
			}
		}
	}
	cout<<dp[0][n-1];
	return 0;
}
