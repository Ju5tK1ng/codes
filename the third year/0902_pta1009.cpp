#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,a[100];
	int cnt=0,len[100];
	memset(len,0,sizeof(len));
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(s[i]!=' '){
			a[cnt][len[cnt]]=s[i];
			len[cnt]++;
		}
		else{
			cnt++;
		}
	}
	for(int i=cnt;i>=0;i--){
		for(int j=0;j<len[i];j++){
			cout<<a[i][j];
		}
		if(i!=0) cout<<' ';
		else cout<<endl;
	}
	return 0;
}
