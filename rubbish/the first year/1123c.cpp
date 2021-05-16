#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int n,a[1010],b[1010],sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		sum+=a[i]*b[i];
	}
	cout<<sum;
	return 0;
}
