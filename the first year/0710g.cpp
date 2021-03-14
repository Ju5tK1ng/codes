#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=50010;
int rank[maxn];
int par[maxn];
void init(int n){
    for(int i=0;i<n;i++){
    	par[i]=i;
        rank[i]=0;
	}
}
int find(int x){
	if(par[x]==x) return x;
	return par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rank[x]<rank[y]){
		par[x]=y;
	}
	else{
		par[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
}
bool same(int x,int y){
	return find(x)==find(y); 
}
int main(){
	int n,k;
	cin>>n>>k;
	init(n);
	int ans=0;
	for(int i=0;i<k;i++){
		int d,x,y;
		scanf("%d %d %d",&d,&x,&y);
	}
	
	cout<<ans<<endl;
	return 0;
}
