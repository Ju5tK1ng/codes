#include<bits/stdc++.h>
using namespace std;
struct Student{
	long long num;
	int test;
}a[1010];
int main(){
	long long tnum;
	int n,m,ttest,ttry;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tnum>>ttry>>ttest;
		a[ttry].num=tnum;
		a[ttry].test=ttest;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>ttry;
		cout<<a[ttry].num<<' '<<a[ttry].test<<endl;
	}
	return 0;
}
