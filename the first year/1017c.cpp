#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int h1,m1,s1,h2,m2,s2,n;
	cin>>n;
	while(n--){
		cin>>h1>>m1>>s1>>h2>>m2>>s2;
		s1=s1+s2;
		m1=m1+m2+s1/60;
		h1=h1+h2+m1/60;
		cout<<h1<<" "<<m1%60<<" "<<s1%60<<endl;
	}
	return 0;
}
