#include<bits/stdc++.h>
using namespace std;
const int maxn=30010;
int n,m,k,ans=0,read,first,t,a[maxn];
int find(int x){
	if(a[x]==x) return a[x];
	return a[x]=find(a[x]);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		a[i]=i;
	}
	for(int i=0;i<m;i++){
		cin>>k>>first;
		int findf=find(first);
		if(i==0) read=first;
		for(int j=1;j<k;j++){
			cin>>t;
			int findt=find(t);
			if(findf!=findt) a[findt]=findf;
		}
	}
	int findr=find(read);
	for(int i=0;i<n;i++){
		if(findr==find(i)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
