#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=310;
const int dx[5]={0,1,-1,0,0};
const int dy[5]={0,0,0,1,-1};
int a[maxn][maxn];
struct xyt{
	int x,y,t;
};
xyt tmp,now;
int bfs(){
	if(a[0][0]==-1) return 0;
	if(a[0][0]==0) return -1;
	tmp.x=tmp.y=tmp.t=0;
	queue <xyt> q;
	q.push(tmp);
	while(!q.empty()){
		now=q.front();
		q.pop();
		for(int i=1;i<5;i++){
			tmp.x=now.x+dx[i];
			tmp.y=now.y+dy[i];
			tmp.t=now.t+1;
			if(tmp.x<0 || tmp.y<0 || tmp.x>=maxn || tmp.y>=maxn) continue;
			if(a[tmp.x][tmp.y]==-1) return tmp.t;
			if(tmp.t>=a[tmp.x][tmp.y]) continue;
			a[tmp.x][tmp.y]=tmp.t;
			q.push(tmp);
		}
	}
	return -1;
}
int main(){
	int m;
	while(scanf("%d",&m)!=EOF){
		int x,y,t;
		memset(a,-1,sizeof(a));
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&x,&y,&t);
			for(int j=0;j<5;j++){
				int tx=x+dx[j];
				int ty=y+dy[j];
				if(tx<0 || ty<0 || tx>=maxn || ty>=maxn) continue;
				if(a[tx][ty]==-1) a[tx][ty]=t;
				else a[tx][ty]=min(a[tx][ty],t);
			}
		}
		printf("%d\n",bfs());
	}
	return 0;
}
