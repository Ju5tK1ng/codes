#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	char a[100];
	while(gets(a)){
		int m='a';
		for(int i=0;i<strlen(a);i++){
			m=max(m,(int)a[i]);
		}
		for(int i=0;i<strlen(a);i++){
			cout<<a[i];
			if(a[i]==m){
				cout<<"(max)";
			}
		}
		cout<<endl;
	}
	return 0;
}