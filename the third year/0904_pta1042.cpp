#include<bits/stdc++.h>
using namespace std;
int a[150],ans;
int main(){
	string s;
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(s[i]>='a' && s[i]<='z'){
			a[s[i]]++;
		}
		else if(s[i]>='A' && s[i]<='Z'){
			a[s[i]+32]++;
		}
	}
	for(int i=97;i<123;i++){
		if(a[ans]<a[i]) ans=i;
	}
	cout<<char(ans)<<' '<<a[ans]<<endl;
	return 0;
}
