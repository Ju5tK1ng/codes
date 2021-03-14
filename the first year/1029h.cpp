#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[20];
	gets(str);
	int ok=0;
	if(str[0]=='-'){
		cout<<"-";
		for(int i=strlen(str)-1;i>0;i--){
			if(str[i]!='0'||ok==1){
				cout<<str[i];
				ok=1;
			}
		}
	}else if(str[0]=='0'){
		cout<<0;
	}else{
		for(int i=strlen(str)-1;i>=0;i--){
			if(str[i]!='0'||ok==1){
				cout<<str[i];
				ok=1;
			}
		}
	}
	cout<<endl;
	return 0;
}
