#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[2][100010],n,cnt;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[0][i+1]=max(c[0][i],a[i]);
	}
	c[1][n-1]=1e9+10;
	for(int i=n-1;i>=0;i--){
		c[1][i-1]=min(c[1][i],a[i]);
	}
	for(int i=0;i<n;i++){
		if(a[i]>c[0][i] && a[i]<c[1][i]){
			b[cnt++]=a[i];
		}
	}
	sort(b,b+cnt);
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		if(i!=cnt-1) cout<<b[i]<<' ';
		else cout<<b[i];
	}
	cout<<endl;
	return 0;
}
