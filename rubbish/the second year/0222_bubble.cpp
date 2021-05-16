#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn];
int main(){
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
		cnt++;
		if(cnt==k){
			for(int k=0;k<n;k++){
				if(k!=n-1) cout<<a[k]<<" ";
				else cout<<a[k]<<endl;
			}
			break;
		}
	}
	return 0;
}
