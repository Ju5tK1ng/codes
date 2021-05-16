#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	char c1,c2;
	int a=0,b=0;
	cin>>s1>>c1>>s2>>c2;
	for(int i=0;i<s1.length();i++){
		if(s1[i]==c1) a=a*10+(c1-'0');
	}
	for(int i=0;i<s2.length();i++){
		if(s2[i]==c2) b=b*10+(c2-'0');
	}
	cout<<a+b<<endl;
	return 0;
}
