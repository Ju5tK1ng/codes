#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10010;
int c[maxn],y[maxn];
int  main(){
	int n,s,cost;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		scanf("%d %d",&c[i],&y[i]);
	}
	cost=c[0];
	long long money=cost*y[0];
	for(int i=1;i<n;i++){
		cost=min(cost+s,c[i]);
		money+=cost*y[i];
	}
	cout<<money<<endl;
	return 0;
}
