#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char s[100];
	int n,i,j,ca,co,ci,cu,ce;
	cin>>n;
	gets(s);
	for(i=0;i<n;i++){
		gets(s);
		ca=co=ci=cu=ce=0;
		for(j=0;j<strlen(s);j++){
			if(s[j]=='a'||s[j]=='A'){
				ca++;
			}
			if(s[j]=='o'||s[j]=='O'){
				co++;
			}
			if(s[j]=='i'||s[j]=='I'){
				ci++;
			}
			if(s[j]=='u'||s[j]=='U'){
				cu++;
			}
			if(s[j]=='e'||s[j]=='E'){
				ce++;
			}
		}
		if(i!=0){
			cout<<endl;
		}
		cout<<"a:"<<ca<<endl
			<<"e:"<<ce<<endl
			<<"i:"<<ci<<endl
			<<"o:"<<co<<endl
			<<"u:"<<cu<<endl;
	}
	return 0;
} 
