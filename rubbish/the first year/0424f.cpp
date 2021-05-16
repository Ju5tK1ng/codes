#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int main(){
	int n,q,a[maxn],x,kase=0;
	while(cin>>n>>q && n){
		cout<<"CASE# "<<++kase<<":"<<endl;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		while(q--){
			cin>>x;
			int p=lower_bound(a,a+n,x)-a;
			if(a[p]==x) cout<<x<<" found at "<<p+1<<endl;
			else cout<<x<<" not found"<<endl;
		}
	}
	return 0;
}
