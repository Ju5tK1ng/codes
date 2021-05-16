#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100010],t=0,ans=0,tl=0,l=0,r,ok=0;
	cin>>n;
	r=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(t<0){
			t=0;
			tl=i;
		}
		t+=a[i];
		if(t>ans || (a[i]==0 && !ok)){
			ans=t;
			l=tl;
			r=i;
			ok=1;
		}
	}
	cout<<ans<<" "<<a[l]<<" "<<a[r]<<endl;
}
