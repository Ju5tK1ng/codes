#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	char t;
	while((t=getchar())!='\n'){
		a[t-'0']++;
	}
	for(int i=0;i<10;i++){
		if(a[i]) cout<<i<<':'<<a[i]<<endl;
	}
	return 0;
}
