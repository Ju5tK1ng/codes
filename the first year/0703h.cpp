#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct cow{
	int t,d;
	bool operator <(const cow& x)const{
		return t*x.d<x.t*d;
	}
}a[100010];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i].t,&a[i].d);
	}
	sort(a,a+n);
	long long ans=0,time=0;
	for(int i=0;i<n;i++){
		ans+=time*a[i].d;
		time+=2*a[i].t;
	}
	cout<<ans<<endl;
	return 0;
}
