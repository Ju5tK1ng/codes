#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	int n,t,grade,cnt=0,ans=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t>>grade;
		cnt=max(cnt,t);
		a[t]+=grade;
	} 
	for(int i=2;i<=cnt;i++){
		if(a[i]>a[ans]) ans=i;
	}
	cout<<ans<<' '<<a[ans]<<endl; 
	return 0;
}
