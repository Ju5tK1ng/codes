#include<bits/stdc++.h>
using namespace std;
const int maxn=3010;
struct edge{
	int v1,v2,w;
}e[maxn];
bool cmp(edge e1,edge e2){
	return e1.w<e2.w;
}
int v[maxn];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>e[i].v1>>e[i].v2>>e[i].w;
	}
	sort(e,e+m,cmp);
	v[e[0].v1]=v[e[0].v2]=1;
	int ans=e[0].w;
	int selected=2,cnt=1;
	while(selected!=n){
		cnt++;
		if(cnt==n){
			cout<<-1<<endl;
			return 0;
		}
		for(int i=1;i<m;i++){
			if(!v[e[i].v1] && v[e[i].v2] || v[e[i].v1] && !v[e[i].v2]){
				v[e[i].v1]=v[e[i].v2]=1;
				selected++;
				ans+=e[i].w;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
