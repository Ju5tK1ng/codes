#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n=5;
	char a[10];
	while(n--){
		gets(a);
		cout<<strlen(a)<<endl;
	}
	return 0;
}
