#include<bits/stdc++.h>
using namespace std;
int a[200],b[200],lack;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s1.length();i++){
		a[s1[i]]++;
	}
	for(int i=0;i<s2.length();i++){
		b[s2[i]]++;
	}
	for(int i=0;i<200;i++){
		if(a[i]<b[i]) lack+=b[i]-a[i];
	}
	if(lack==0) cout<<"Yes "<<s1.length()-s2.length()<<endl;
	else cout<<"No "<<lack<<endl;
	return 0;
}
