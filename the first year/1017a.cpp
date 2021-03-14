#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int num,r,sum;
	char s[100];
	while(cin>>r){
		gets(s);
		gets(s);
		sum=0;
		for(int i=0;i<strlen(s);i++){
			if(s[i]>='0'&&s[i]<='9'){
				num=s[i]-'0';
			}else if(s[i]>='A'&&s[i]<='F'){
				num=s[i]-55;
			}
			sum=sum*r+num;
		}
		cout<<sum<<endl;
	}
}
