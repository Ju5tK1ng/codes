#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long a,b;
	cin>>a>>b;
	long long  M=max(a,b),m=a+b-M;
	long long  maxn=M,minn=m;
	while(maxn%minn!=0 && minn!=1){
		long long  t=minn;
		minn=maxn%t;
		maxn=t;
	}
	long long  x,y=0;
	while(M*y%m!=minn && m-M*y%m!=minn){
		y++;
	}
	if(M*y%m==minn){
		x=-M*y/m;
		if(a>=b) swap(x,y);
		cout<<x<<" "<<y<<endl;
	}
	else{
		x=M*y/m+1;
		y=-y;
		if(a>=b) swap(x,y);
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
