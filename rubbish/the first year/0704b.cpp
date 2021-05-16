#include<iostream>
using namespace std;
int a[1000010];
int main(){
	int n;
	cin>>n;
	a[1]=1;
	for(int i=2;i<=n;i++){
		if(i%2) a[i]=a[i-1];
		else a[i]=a[i-1]+a[i/2];
		a[i]%=1000000000;
	}
	cout<<a[n]<<endl;
	return 0;
}
