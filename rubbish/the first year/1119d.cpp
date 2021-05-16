#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	double sum=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		double pro=1;
		for(int j=1;j<=i;j++){
			pro*=j;
		}
		sum+=1/pro;
	}
	printf("%.10lf",sum);
	return 0;
}
