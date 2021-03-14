#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=b.length();i<a.length();i++){
		b+='0';
	}
	for(int i=0;i<b.length() && i<a.length();i+=2){
		int t=((a[i]-'0')+(b[i]-'0'))%13;
		if(t==12) b[i]='K';
		else if(t==11) b[i]='Q';
		else if(t==10) b[i]='J';
		else b[i]=char(t+'0'); 
	}
	for(int i=1;i<b.length() && i<a.length();i+=2){
		int t=b[i]-a[i];
		if(t<0) t+=10;
		b[i]=char(t+'0');
	}
	reverse(b.begin(),b.end());
	cout<<b<<endl;
	return 0;
}
