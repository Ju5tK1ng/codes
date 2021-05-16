#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	int a[100],cnt=0;
	memset(a,0,sizeof(a));
	cin>>s1>>s2;
	for(int i=0;i<s2.length();i++){
		for(;cnt<s1.length();cnt++){
			if(s1[cnt]==s2[i]){
				if(i!=s2.length()-1){
					cnt++;
					break;
				}
			}
			else{
				if(s1[cnt]>='a' && s1[cnt]<='z') s1[cnt]-=32;
				if(a[s1[cnt]]==0){
					cout<<s1[cnt];
					a[s1[cnt]]=1;
				}
			}
		}
	}
	cout<<endl;
	return 0;
}
