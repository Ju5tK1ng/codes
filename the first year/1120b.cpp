#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int l,r,sum=0;
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		int t=i;
		while(t){
			if(t%10==2) sum++;
			t/=10;
		}
	}
	cout<<sum;
	return 0;
}
