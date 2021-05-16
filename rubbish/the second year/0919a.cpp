#include<bits/stdc++.h>
using namespace std;
int a[30],b[30];
int main(){
	int n,r;
	while(cin>>n>>r && r!=-1){
		a[r]=n;
	}
	while(cin>>n>>r && r!=-1){
		b[r]=n;
	}
	int t=30;
	for(int i=20;i>=0;i--){
		a[i]+=b[i];
		if(a[i]!=0){
			t=i;
		}
	}
	for(int i=20;i>=0;i--){
		if(a[i]!=0){
			cout<<a[i];
			if(i!=0) cout<<"x^"<<i;
			if(i!=t) cout<<"+";
			else cout<<endl;
		}
	}
	if(t==30) cout<<0<<endl;
	return 0;
}
