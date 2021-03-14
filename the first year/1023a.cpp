#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int y[10000],m[10000],d[10000],t,sum;
	while(cin>>t){
		for(int i=0;i<t;i++){
			sum=0;
			scanf("%d-%d-%d",&y[i],&m[i],&d[i]);
			if(m[i]>2) y[i]++;
			if(m[i]==2&&d[i]==29){
				cout<<-1<<endl;
				break;
			}
			for(int j=y[i];j<y[i]+18;j++){
				if(j%4==0&&j%100!=0||j%400==0) sum+=366;
				else sum+=365;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
