#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n,a[100010],cnt=1,start=0;
	a[0]=2;
	cin>>m>>n;
	for(int i=3;cnt<n+10;i++){
		bool ok=true;
		int root=sqrt(i);
		for(int j=0;j<cnt && a[j]<=root;j++){
			if(i%a[j]==0){
				ok=false;
				break;
			}
		}
		if(ok){
			a[cnt++]=i;
		}
	}
	for(int i=m-1;i<=n-1;i++){
		if(i%10!=(m+8)%10 && i!=n-1) cout<<a[i]<<" ";
		else cout<<a[i]<<endl;
	}
	return 0;
}
