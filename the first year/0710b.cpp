#include<iostream>
#include<cstdio>
using namespace std;
char c[110][110];
int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,-1,-1,1};
int n,m;
void dfs(int x,int y){
	c[x][y]='.';
	for(int i=0;i<8;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0 && nx<n && ny>=0 && ny<m && c[nx][ny]=='W') dfs(nx,ny); 
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%s",&c[i]);
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(c[i][j]=='W'){
				cnt++;
				dfs(i,j);
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
