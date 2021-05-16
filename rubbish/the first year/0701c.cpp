#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		char a[100];
		cin>>a;
		int cnt=0;
		for(int i=0;i<=strlen(a);i++){
			if(a[i]>='0' && a[i]<='9') cnt++;
		}
		cout<<cnt<<endl;
	} 
	return 0;
}
