#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double a[40],b[40];
	a[0]=1,a[1]=2,b[0]=2;
	for(int i=2;i<35;i++){
		a[i]=a[i-1]+a[i-2];
		b[i-1]=a[i]/a[i-1]+b[i-2];
	}
	int n;
	cin>>n;
	printf("%.4lf",b[n-1]);
	return 0;
}
