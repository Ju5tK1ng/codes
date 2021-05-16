#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	char a[100];
	while(cin>>a){
		char m=a[0];
		for(int i=1;i<strlen(a);i++){
			m=max(m,a[i]);
		}
		for(int i=0;i<strlen(a);i++){
			cout<<a[i];
			if(a[i]==m) cout<<"(max)";
		}
		cout<<endl;
	} 
	return 0;
}
