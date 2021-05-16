#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
struct edge{
	int v1,v2,w;
}e[maxn];
bool cmp(edge e1,edge e2){
	return e1.w<e2.w;
}
int v[maxn],selected=2,cnt,n,ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>e[i].v1>>e[i].v2>>e[i].w;
		if(!v[e[i].v1]){
			v[e[i].v1]=1;
			cnt++;
		}
		if(!v[e[i].v2]){
			v[e[i].v2]=1;
			cnt++;
		}
	}
	sort(e,e+n,cmp);
	v[e[0].v1]=v[e[0].v2]=0;
	ans=e[0].w;
	while(selected!=cnt){
		for(int i=1;i<n;i++){
			if(!v[e[i].v1] && v[e[i].v2] || v[e[i].v1] && !v[e[i].v2]){
				v[e[i].v1]=v[e[i].v2]=0;
				selected++;
				ans+=e[i].w;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
