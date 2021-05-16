#include<bits/stdc++.h>
using namespace std;
int main(){
	void *p;
	int cnt=0;
	while(p=malloc(1024*1024)){
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
