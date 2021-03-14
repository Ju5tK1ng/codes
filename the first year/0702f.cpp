#include<iostream>
#include<cstring>
#include<set>
using namespace std;
char a[5][5];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
set <string> s;
void dfs(int x,int y,string str,int k){
	if(k==5){
		s.insert(str);
		return;
	}
	for(int i=0;i<4;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx<0 || ty<0 || tx>4 || ty>4) continue;
		dfs(tx,ty,str+a[tx][ty],k+1);
	}
}
int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			string str;
			str+=a[i][j];
			dfs(i,j,str,0);
		}
	}
	cout<<s.size()<<endl;
	return 0;
}
