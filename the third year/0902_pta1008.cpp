#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[110];
	cin>>n>>m;
	m%=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-m;i<n*2-m;i++){
		if(i!=n*2-m-1) cout<<a[i%n]<<' ';
		else cout<<a[i%n]<<endl;
	}
	return 0;
}
