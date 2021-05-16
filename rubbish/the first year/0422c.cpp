#include<bits/stdc++.h>
using namespace std;
int main(){
	char s1[200],s2[200];
	while(cin>>s1>>s2){
		int cnt1[26]={0},cnt2[26]={0};
		for(int i=0;i<strlen(s1);i++) cnt1[s1[i]-'A']++;
		for(int i=0;i<strlen(s2);i++) cnt2[s2[i]-'A']++;
		sort(cnt1,cnt1+26);
		sort(cnt2,cnt2+26);
		int ok=1;
		for(int i=0;i<26;i++){
			if(cnt1[i]!=cnt2[i]) ok=0;
		}
		if(ok) cout<<"Yes"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
