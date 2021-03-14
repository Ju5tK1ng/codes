#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
	int n,member,team,grade,ans=0;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>team>>c>>member>>grade;
		a[team]+=grade;
	}
	for(int i=1;i<1010;i++){
		if(a[ans]<a[i]) ans=i;
	}
	cout<<ans<<' '<<a[ans]<<endl;
	return 0;
}
