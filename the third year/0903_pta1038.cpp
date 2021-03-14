#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	int n,k,t;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		a[t]++;
	}
	cin>>k;
	for(int i=0;i<k;i++){
		scanf("%d",&t);
		if(i!=k-1) cout<<a[t]<<' ';
		else cout<<a[t]<<endl;
	}
	return 0;
}
