#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int cntp,cntt,ans;
int main(){
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='T') cntt++;
	}
	for(int i=0;i<len;i++){
		if(s[i]=='P') cntp++;
		else if(s[i]=='T') cntt--;
		else ans=(ans+cntp*cntt)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
