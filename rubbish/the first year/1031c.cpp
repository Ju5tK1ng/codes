#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int N,M,d[6000],ok=0;
	cin>>N>>M;
	memset(d,1,sizeof(d));
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			if(j%i==0) d[j]=!d[j];
		}
	}
	for(int i=1;i<=N;i++){
		if(!d[i]&&ok) cout<<","<<i;
		if(!d[i]&&!ok){
			cout<<i;
			ok=1;
		}
	}
	cout<<endl;
	return 0;
}
