#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		int cnt=0,m;
		for(int i=0;i<n;i++){
			cin>>m;
			cnt+=m/100;
			m%=100;
			cnt+=m/50;
			m%=50;
			cnt+=m/10;
			m%=10;
			cnt+=m/5;
			m%=5;
			cnt+=m/2;
			m%=2;
			cnt+=m;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
