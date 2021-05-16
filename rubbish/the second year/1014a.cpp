#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
const int dx[8]={0,1,1,1,0,-1,-1,-1};
const int dy[8]={-1,-1,0,1,1,1,0,-1};
bool a[maxn][maxn];
int ans[10000][2];
int m,n,cnt;
void dfs(int x,int y,int cnt){
	a[x][y]=1;
	for(int i=0;i<8;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx<0 || tx>=m || ty<0 || ty>=n || a[tx][ty]==1) continue;
		ans[cnt][0]=tx+1;
		ans[cnt][1]=ty+1;		
		if(ans[cnt][0]==m && ans[cnt][1]==n){
			for(int i=0;i<=cnt;i++){
				cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
			}
		}
		dfs(tx,ty,++cnt);
		cnt--;
	}
}
int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	ans[0][0]=ans[0][1]=1;
	dfs(0,0,1);
	return 0;
}
