#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int l,n,ant;
		cin>>l>>n;
		int mi=0,ma=0;
		for(int i=0;i<n;i++){
			scanf("%d",&ant);
			mi=max(mi,min(ant,l-ant));
			ma=max(ma,max(ant,l-ant));
		}
		cout<<mi<<" "<<ma<<endl;
	}
	return 0;
}
