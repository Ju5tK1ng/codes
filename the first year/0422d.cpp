#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n && n!=-1){
		char s1[50],s2[50];
		cin>>s1>>s2;
		int cnt[26]={0};
		for(int i=0;i<strlen(s1);i++) cnt[s1[i]-'a']++;
		int wrong=0;
		for(int i=0;i<strlen(s2);i++){
			if(cnt[s2[i]-'a']==0) wrong++;
			else cnt[s2[i]-'a']=0;
		}
		sort(cnt,cnt+26);
		cout<<"Round "<<n<<endl;
		if(wrong>6) cout<<"You lose."<<endl;
		else if(cnt[25]==0) cout<<"You win."<<endl;
		else cout<<"You chickended out."<<endl;
	}
	return 0;
}
