#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10],n;
void solve(){
	while(!a[0]) next_permutation(a,a+n);
	int ans=99999999;
	int mid=n/2;
	do{
		if(a[mid]){
			int n1=a[0],n2=a[mid];
			for(int i=1;i<mid;i++) n1=n1*10+a[i];
			for(int i=mid+1;i<n;i++) n2=n2*10+a[i];
			ans=min(ans,abs(n1-n2));
		}
	}while(next_permutation(a,a+n));
	cout<<ans<<endl;
}
int main(){
	int t; 
	cin>>t;
	getchar();
	while(t--){
		n=0;
		char c;
		while((c=getchar())!='\n'){
			if(c==' ') continue;
			a[n++]=c-'0';
		}
		if(n==2) cout<<a[1]-a[0]<<endl;
		else solve();
	}
	return 0;
}
