#include<bits/stdc++.h>
using namespace std;
float a[100010],b[100010];
int main(){
	string p;
	float n;
	char c;
	int r;
	cin>>p;
	for(int i=0;i<p.length();i++){
		if(p[i]=='x' && (i==0 || p[i-1]=='+' || p[i-1]=='-')) p.insert(i,"1");
	}
	istringstream s1(p);
	while(s1){
		n=r=0;
		s1>>n>>c>>c>>r;
		a[r]=n;
	}
	cin>>p;
	for(int i=0;i<p.length();i++){
		if(p[i]=='x' && (i==0 || p[i-1]=='+' || p[i-1]=='-')) p.insert(i,"1");
	}
	istringstream s2(p);
	while(s2){
		n=r=0;
		s2>>n>>c>>c>>r;
		b[r]=n;
	}
	int t=-1;
	for(int i=0;i<=100000;i++){
		a[i]+=b[i];
		if(a[i]!=0) t=i;
	}
	for(int i=100000;i>=0;i--){
		if(a[i]!=0){
			if(a[i]>0){
				if(i!=t) cout<<'+';
				if(a[i]!=1 || i==0) cout<<a[i];
			}
			else{
				cout<<'-';
				if(a[i]!=-1 || i==0) cout<<-a[i];
			}
			if(i!=0) cout<<"x^"<<i;
		}
	}
	if(t==-1) cout<<0;
	cout<<endl;
	return 0;
}
