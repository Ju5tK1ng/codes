#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[10010],cnt=1,ans=0;
	a[0]=2;
	cin>>n;
	for(int i=3;i<=n;i++){
		bool ok=true;
		for(int j=0;j<cnt;j++){
			if(i%a[j]==0){
				ok=false;
				break;
			}
		}
		if(ok){
			a[cnt++]=i;
			if(a[cnt-1]-a[cnt-2]==2) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
