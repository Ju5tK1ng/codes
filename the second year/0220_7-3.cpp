#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
vector<int> a;
vector<int> v[maxn];
int maxdeep=0;
int dfs(int n,int deep){
	if(deep>maxdeep){
		maxdeep=deep;
		a.clear();
	}
	if(deep==maxdeep) a.push_back(n);
	for(int i=0;i<v[n].size();i++){
		dfs(v[n][i],deep+1);
	}
}
int main(){
	int n,root;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		if(t==-1) root=i;
		else v[t].push_back(i);
	}
	dfs(root,1);
	sort(a.begin(),a.end());
	cout<<maxdeep<<endl;
	for(int i=0;i<a.size();i++){
		if(i!=a.size()-1) cout<<a[i]<<" ";
		else cout<<a[i]<<endl;
	}
	return 0;
}
