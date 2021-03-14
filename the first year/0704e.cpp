#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2010;
char s[2010];
int dp[maxn][maxn];
int cost[30];
int main(){
	int n,m,add,del;
	char c;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c>>add>>del;
		cost[c-'a']=min(add,del);
	}
	for(int i=m-1;i>=0;i--){
		for(int j=i+1;j<m;j++){
			if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
			else dp[i][j]=min(dp[i+1][j]+cost[s[i]-'a'],dp[i][j-1]+cost[s[j]-'a']);
		}
	}
	cout<<dp[0][m-1]<<endl;
}
