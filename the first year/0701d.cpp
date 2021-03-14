#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,a[55];
	a[1]=1;
	a[2]=2;
	a[3]=3;
	a[4]=4;
	for(int i=5;i<55;i++){
		a[i]=a[i-1]+a[i-3];
	}
	while(cin>>n){
		if(n==0) break;
		cout<<a[n]<<endl;
	}
	return 0;
}
