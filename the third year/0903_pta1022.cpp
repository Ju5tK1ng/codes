#include<bits/stdc++.h>
using namespace std;
int ans[100]; 
int main(){
	int a,b,d,cnt=0;
	cin>>a>>b>>d;
	a+=b;
	while(a){
		ans[cnt++]=a%d;
		a/=d;
	}
	if(!cnt) cnt=1;
	for(int i=cnt-1;i>=0;i--){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
