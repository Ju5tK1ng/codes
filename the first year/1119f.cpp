#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,a[1010];
	cin>>m;
	while(m--){
		cin>>n;
		cin>>a[n];
		if(n==0) cout<<0;
		for(int i=n;i>0;i--){
			cin>>a[i-1];
			cout<<a[i]*i;
			if(i>1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
