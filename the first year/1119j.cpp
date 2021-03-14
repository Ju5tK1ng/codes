#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t=i;
		while(t){
			if(t%10==1) sum++;
			t/=10;
		}
	}
	cout<<sum;
	return 0;
}
