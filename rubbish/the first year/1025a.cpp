#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int main()
{
	double temp,sum=0;
	int i=1;
	do{
		temp=1.0/i;
		if(i%4==1) sum+=temp;
		else sum-=temp;
		i+=2;
	}while(temp>=1e-10);
	printf("%.8lf\n",sum*4);
	printf("%.2f",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
