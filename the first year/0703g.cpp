#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[110];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	double ans=a[n-1];
	for(int i=n-2;i>=0;i--){
		ans=2*sqrt(a[i]*ans);
	}
	printf("%.3f\n",ans);
	return 0;
}
