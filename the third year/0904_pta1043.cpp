#include<bits/stdc++.h>
using namespace std;
int a[6],cnt;
int main(){
	string s1,s2="PATest";
	cin>>s1;
	for(int i=0;i<s1.length();i++){
		for(int j=0;j<s2.length();j++){
			if(s1[i]==s2[j]){
				a[j]++;
				break;
			}
		}
	}
	for(int i=0;a[0] || a[1] || a[2] || a[3] || a[4] || a[5];i=(i+1)%6){
		if(a[i]){
			cout<<s2[i];
			a[i]--;
		}
	}
	cout<<endl;
	return 0;
}
