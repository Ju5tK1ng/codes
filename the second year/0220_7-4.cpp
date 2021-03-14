#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
vector<int> v[maxn];
int a[maxn];
int ans;
int maxdeep=0;
int dfs(int n,int deep){
	if(deep>maxdeep){
		maxdeep=deep;
		ans=n;
	}
	for(int i=0;i<v[n].size();i++){
		dfs(v[n][i],deep+1);
	}
}
int main(){
	int n,root=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		for(int j=0;j<c;j++){
			int t;
			cin>>t;
			a[t]=1;
			v[i].push_back(t);
		}
	}
	while(a[root]) root++;
	dfs(root,1);
	cout<<ans<<endl;
	return 0;
}
