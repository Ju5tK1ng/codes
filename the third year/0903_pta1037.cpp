#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	char ch;
	cin>>a>>ch>>b>>ch>>c>>d>>ch>>e>>ch>>f;
	if(a>d || a==d && b>e || a==d && b==e && c>f){
		swap(a,d);
		swap(b,e);
		swap(c,f);
		cout<<'-';
	}
	if(c<=f){
		f-=c;
	}
	else{
		f+=29-c;
		e--;
	}
	if(b<=e){
		e-=b;
	}
	else{
		e+=17-b;
		d--;
	}
	d-=a;
	cout<<d<<'.'<<e<<'.'<<f<<endl;
	return 0;
}
