#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int i;
	for(i=0;i<s1.length();i++){
		if(s1[i]>='A' && s1[i]<='G' && s1[i]==s2[i]){
			switch(s1[i]){
				case 'A':cout<<"MON ";break;
				case 'B':cout<<"TUE ";break;
				case 'C':cout<<"WED ";break;
				case 'D':cout<<"THU ";break;
				case 'E':cout<<"FRI ";break;
				case 'F':cout<<"SAT ";break;
				case 'G':cout<<"SUN ";break;
			}
			break;
		}
	}
	for(i=i+1;i<s1.length();i++){
		if((s1[i]>='0' && s1[i]<='9' || s1[i]>='A' && s1[i]<='N') && s1[i]==s2[i]){
			if(s1[i]<='9') cout<<'0'<<s1[i]-'0'<<':';
			else cout<<s1[i]-'A'+10<<':'; 
			break;
		}
	}
	for(int i=0;i<s3.length();i++){
		if((s3[i]>='a' && s3[i]<='z' || s3[i]>='A' && s3[i]<='Z') && s3[i]==s4[i]){
			if(i<10) cout<<'0'<<i<<endl;
			else cout<<i<<endl;
			break;
		}
	}
}
