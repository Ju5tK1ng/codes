#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int a[maxn],b[maxn],m,n,cnt=1,path[2][20];
void pre_order(int i){
	if(b[cnt]){
		a[i]=b[cnt++];
		if(b[cnt]<a[i]) pre_order(i*2);
		if(b[cnt]>a[i] && (b[cnt]<a[i/2] || i==1)) pre_order(i*2+1);
	}
}
int find_lca(int num,int uv){
	int ans=0,t=1;
	path[uv][0]=a[1];
	while(path[uv][ans]!=num){
		if(num<path[uv][ans]) t*=2;
		else t=t*2+1;
		if(t>maxn) return -1;
		ans++;
		path[uv][ans]=a[t];
	}
	return ans;
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	pre_order(1);
	while(m--){
		int u,v;
		cin>>u>>v;
		int cu=find_lca(u,0);
		int cv=find_lca(v,1);
		if(cu==-1 && cv==-1) cout<<"ERROR: "<<u<<" and "<<v<<" are not found."<<endl;
		else if(cu==-1) cout<<"ERROR: "<<u<<" is not found."<<endl;
		else if(cv==-1) cout<<"ERROR: "<<v<<" is not found."<<endl;
		else{
			while(path[0][cu]!=path[1][cv]){
				if(cu>cv) cu--;
				else if(cu<cv) cv--;
				else{
					cu--;
					cv--;
				}
			}
			if(path[0][cu]==u) cout<<u<<" is an ancestor of "<<v<<"."<<endl;
			else if(path[1][cv]==v) cout<<v<<" is an ancestor of "<<u<<"."<<endl;
			else cout<<"LCA of "<<u<<" and "<<v<<" is "<<path[0][cu]<<"."<<endl;
		}
		memset(path,-1,sizeof(path));
	}
	return 0;
}
