#include<iostream>
using namespace std;
int main(){
	int t,m,n,a[30];
	cin>>t;
	while(t--){
		cin>>m>>n;
		long long rmb=0;
		for(int i=0;i<n;i++){
			cin>>a[i];	
		}
		for(int i=0;i<n;i++){
			if(a[i]==1 && m>i+1){
				m=i+1;
				break;
			}
		}
		int e=n-m;
		if(e){
			rmb=10000;
			for(int i=0;i<e;i++){
				rmb*=2;
			}
			rmb-=10000;
		}
		cout<<rmb<<" RMB"<<endl;
	}
	return 0;
}
