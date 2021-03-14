#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,a[maxn],b[maxn];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int na=0,nb=0,cnt=-1;
	while(na+nb<n-1){
		if(a[na]>=b[nb]) nb++;
		else na++;
	}
	if(a[na]>=b[nb]) cout<<b[nb]<<endl;
	else cout<<a[na]<<endl;
	return 0;
}
