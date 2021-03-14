#include<bits/stdc++.h>
using namespace std;
const int maxn=11;
int a[maxn];
int main(){
	int c,n;
	cin>>c;
	while(c--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		int t=1;
		while(a[t]==a[0] && t!=n){
			t++;
		} 
		if(t==n) cout<<"NO"<<endl;
		else cout<<a[t]<<endl;
	}
	return 0;
}
