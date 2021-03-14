#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
void numchange(int N,int R);
int main()
{
	int N,R;
	while(cin>>N>>R){
		if(N<0){
			N=-N;
			cout<<"-";
		}
		numchange(N,R);
		cout<<endl;
	}
	return 0;
}
void numchange(int N,int R){
	int n;
	if(N){
		numchange(N/R,R);
		n=N%R;
		if(n<10){
			cout<<n;
		}else{
			printf("%c",n+55);
		}
	}
}
