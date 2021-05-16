#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	float x,pro=1,sum=1;
	cin>>x>>n;
	for(int i=1;i<=n;i++){
		pro*=x;
		sum+=pro;
	}
	printf("%.2lf",sum);
	return 0;
}
