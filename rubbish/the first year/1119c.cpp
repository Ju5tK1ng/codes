#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int pro=1;
		for(int j=1;j<=i;j++){
			pro*=j;
		}
		sum+=pro;
	}
	cout<<sum;
	return 0;

