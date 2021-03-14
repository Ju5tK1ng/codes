#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,sum=0,k=10,t;
	cin>>n;
	while(n*10/k){
		if(n%k/(k/10)==0) sum+=n/k*k/10;
		else if(n%k/(k/10)==1) sum+=n/k*k/10+n%(k/10)+1;
		else sum+=(n/k+1)*k/10;
		k*=10;
	}
	cout<<sum;
	return 0;
}
