#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
const int modulo=1e9+7;
int a[maxn],b[maxn],ans[maxn],n,m;
int main(){
	cin>>n>>m;
	b[0]=2;
	for(int i=1;i<n;i++){
		b[i]=b[i-1]*2%modulo;
	}
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		ans[i]=ans[i-1]*2%modulo;
		for(int j=i-1;j>=0;j--){
			if(abs(a[i]-a[j])<=m){
				if(j!=0) ans[i]=(ans[i]+b[j-1]-ans[j-1])%modulo;
				else ans[i]=(ans[i]+1)%modulo;
			}
		}
	}
	cout<<ans[n-1]<<endl;
	return 0;
}
