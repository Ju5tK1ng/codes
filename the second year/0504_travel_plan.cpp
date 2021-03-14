#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int inf=1e9;
int n,m,s,d,x,y,z,w,dp[maxn][maxn][2],vis[maxn],dis[maxn][2];
void Dijkstra(int u){
	for(int i=0;i<n;i++){
		dis[i][0]=dp[u][i][0];
		dis[i][1]=dp[u][i][1];
	}
	vis[u]=1;
	for(int t=1;t<n;t++){
		int minn[2]={inf,inf},temp=inf;
		for(int i=0;i<n;i++){
			if(!vis[i] && (dis[i][0]<minn[0] || dis[i][0]==minn[0] && dis[i][1]<minn[1])){
				minn[0]=dis[i][0];
				minn[1]=dis[i][1];
				temp=i;
			}
		}
		if(temp==inf) break;
		vis[temp]=1;
		for(int i=0;i<n;i++){
			if(dp[temp][i][0]+dis[temp][0]<dis[i][0] || dp[temp][i][0]+dis[temp][0]==dis[i][0] && dp[temp][i][1]+dis[temp][1]<dis[i][1]){
				dis[i][0]=dp[temp][i][0]+dis[temp][0];
				dis[i][1]=dp[temp][i][1]+dis[temp][1];
			}
		}
	}
}
int main(){
	cin>>n>>m>>s>>d;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j][0]=dp[i][j][1]=inf;
			if(i==j){
				dp[i][j][0]=dp[i][j][1]=0;
			}
		}
	}
	for(int i=0;i<m;i++){
		cin>>x>>y>>z>>w;
		dp[x][y][0]=dp[y][x][0]=z;
		dp[x][y][1]=dp[y][x][1]=w;
	}
	Dijkstra(s);
	cout<<dis[d][0]<<" "<<dis[d][1]<<endl;
	return 0;
} 
