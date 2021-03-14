#include<bits/stdc++.h>
using namespace std;
struct Num{
	int parent=-1;
	bool ok=false;
}num[1100000];
int main(){
	int k,n[110],ans[110],cnt=0;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>n[i];
		if(num[n[i]].ok==true) continue;
		else{
			num[n[i]].parent=n[i];
			int t=n[i];
			while(t!=1){
				if(t%2==0){
					t/=2;
				}
				else{
					t=(t*3+1)/2;
				}
				num[t].parent=n[i];
				num[t].ok=true;
			}
		}
	}
	for(int i=0;i<k;i++){
		if(num[n[i]].parent==n[i]){
			ans[cnt++]=n[i];
		}
	}
	sort(ans,ans+cnt);
	for(int i=cnt-1;i>=0;i--){
		if(i!=0) cout<<ans[i]<<' ';
		else cout<<ans[i]<<endl;
	}
	return 0;
}
