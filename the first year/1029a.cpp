#include<iostream>
#include<cstdio>
using namespace std;
int a[12];
int main()
{
	int sum=0,money=0,ok=1;
	for(int i=0;i<12;i++){
		cin>>a[i];
		if(money+300<a[i]){
			cout<<-i-1<<endl;
			ok=0;
			break;
		 }
		money+=(300-a[i]);
		sum+=money/100*100;
		money%=100;
	 }
	if(ok==1)
	cout<<money+sum*1.2<<endl;
	return 0;
}
