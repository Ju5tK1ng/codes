#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int sum,n,i,c,num;
	while(cin>>n){
		c=1;
		sum=0;
		while(n/10000/c){
			c*=10000;
		}
		while(c){
			num=n/c;
			sum=num/1000;
			num%=1000;
			sum=num/100+sum*2;
			num%=100;
			sum=num/10+sum*2;
			num%=10;
			sum=num+sum*2;
			n%=c;
			c/=10000;
			if(sum<10){
				cout<<sum;
			}else{
				printf("%c",sum+55);
			}
			sum=0;
		}
		cout<<endl;
	}
	return 0;
}
	
