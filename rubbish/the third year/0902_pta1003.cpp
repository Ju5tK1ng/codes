#include<bits/stdc++.h>
using namespace std;
int main(){
	int cnt[5],n;
	cin>>n;
	while(n--){
		bool ok=true;
		string s;
		memset(cnt,0,sizeof(cnt));
		cin>>s;
		for(int i=0;i<s.length();i++){
			if(s[i]=='P'){
				cnt[1]++;
				break;
			}
			else if(s[i]=='A'){
				cnt[0]++;
			}
			else{
				ok=false;
				break;
			}
		}
		for(int i=cnt[0]+1;i<s.length();i++){
			if(s[i]=='T'){
				cnt[3]++;
				break;
			}
			else if(s[i]=='A'){
				cnt[2]++;
			}
			else{
				ok=false;
				break;
			}
		}
		for(int i=cnt[0]+cnt[2]+2;i<s.length();i++){
			if(s[i]=='A'){
				cnt[4]++;
			}
			else{
				ok=false;
				break;
			}
		}
		if(!ok){
			cout<<"NO"<<endl;
		}
		else{
			if(cnt[0]==0 && cnt[1]==1 && cnt[2]>=1 && cnt[3]==1 && cnt[4]==0 || cnt[0]!=0 && cnt[4]!=0 && cnt[4]/cnt[0]==cnt[2] && cnt[4]%cnt[0]==0 && cnt[1]==1 && cnt[3]==1){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
