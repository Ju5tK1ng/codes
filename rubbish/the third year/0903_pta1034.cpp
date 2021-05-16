#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
void printNum(ll a,ll b){
	if(a!=0){
		ll k=gcd(a,b);
		a/=k;
		b/=k;
	}
	if(b<0){
		a=-a;
		b=-b;
	}
	if(a==0) cout<<0;
	else if(a<0){
		cout<<"(-";
		a=-a;
		if(a/b!=0) cout<<a/b;
		if(a/b!=0 && a%b!=0) cout<<' ';
		if(a%b!=0) cout<<a%b<<'/'<<b;
		cout<<')';
	}
	else{
		if(a/b!=0) cout<<a/b;
		if(a/b!=0 && a%b!=0) cout<<' ';
		if(a%b!=0) cout<<a%b<<'/'<<b;
	}
}
int main(){
	ll a[2],b[2];
	scanf("%ld/%ld %ld/%ld",&a[0],&a[1],&b[0],&b[1]);
	printNum(a[0],a[1]);cout<<" + ";printNum(b[0],b[1]);cout<<" = ";printNum(a[0]*b[1]+a[1]*b[0],a[1]*b[1]);cout<<endl;
	printNum(a[0],a[1]);cout<<" - ";printNum(b[0],b[1]);cout<<" = ";printNum(a[0]*b[1]-a[1]*b[0],a[1]*b[1]);cout<<endl;
	printNum(a[0],a[1]);cout<<" * ";printNum(b[0],b[1]);cout<<" = ";printNum(a[0]*b[0],a[1]*b[1]);cout<<endl;
	printNum(a[0],a[1]);cout<<" / ";printNum(b[0],b[1]);cout<<" = ";if(b[0]==0) cout<<"Inf";else printNum(a[0]*b[1],a[1]*b[0]);cout<<endl;
	return 0;
}
