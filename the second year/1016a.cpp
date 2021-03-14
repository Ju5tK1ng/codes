#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
const int dx[8]={1,1,0,1,-1,-1,-1,0};
const int dy[8]={1,0,1,-1,1,-1,0,-1};
struct Node{
	int x,y,pre,cnt;
}node[maxn*maxn];
queue<Node> que;
bool a[maxn][maxn];
int m,n,cnt=0;
void print(int cnt){
	if(node[cnt].pre!=-1){
		print(node[cnt].pre);
		cout<<node[cnt].x+1<<" "<<node[cnt].y+1<<endl;
	}
	else cout<<"1 1"<<endl;
}
void bfs(){
	node[0].x=node[0].y=0,node[0].pre=-1,node[0].cnt=0;
	que.push(node[0]);
	while(!que.empty()){
		Node tnode=que.front();
		que.pop();
		for(int i=0;i<8;i++){
			int tx=tnode.x+dx[i];
			int ty=tnode.y+dy[i];
			if(tx<0 || tx>=m || ty<0 || ty>=n || a[tx][ty]==1) continue;
			a[tx][ty]=1;
			cnt++;
			node[cnt].x=tx,node[cnt].y=ty,node[cnt].pre=tnode.cnt,node[cnt].cnt=cnt;
			que.push(node[cnt]);
			if(tx==m-1 && ty==n-1) return;
		}
	}
}
int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	bfs();
	print(cnt);
	return 0;
}
