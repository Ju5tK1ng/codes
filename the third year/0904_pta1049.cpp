#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	double a[100010];
	long long ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans+=(long long)(a[i]*1000)*(i+1)*(n-i);
	}
	printf("%.2lf\n",ans/1000.0);
	return 0;
}
