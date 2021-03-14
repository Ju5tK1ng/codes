#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
int n,ok,a[maxn],v[maxn];
char m[maxn][maxn];
void dps(int t,int cnt){
	if(ok) return;
	a[cnt]=t;
	if(cnt==n-1 && (m[t][0]=='W' || m[0][t]=='L')){
		ok=1;
		return;
	}
	int loop=0;
	for(int i=1;i<n;i++){
		if(!v[i] && (m[i][0]=='W' || m[0][i]=='L')) loop=1;
	}
	if(!loop) return;
	for(int i=1;i<n;i++){
		if(!v[i] && (m[t][i]=='W' || m[i][t]=='L')){
			v[i]=1;
			dps(i,cnt+1);
			v[i]=0;
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>m[i][j];
		}
	}
	v[0]=1;
	dps(0,0);
	if(ok){
		for(int i=0;i<n;i++){
			if(i!=n-1) cout<<a[i]+1<<" ";
			else cout<<a[i]+1<<endl;
		}
	}
	else cout<<"No Solution"<<endl;
	return 0;
}
