#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int r,b;
	while(cin>>r>>b){
		if(r<b){
			swap(r,b);
		}
		cout<<b<<" "<<(r-b)/2<<endl;
	}
	return 0;
}
