#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a>b){
		cout<<a;
	}
	if(!(a>b)){
		if(b>c){
			cout<<b;
		}else{
			cout<<c;
		}
	}
	return 0;
}
