#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	string s2[13]={"    ","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	string s;
	int n;
	cin>>n;
	cin.get();
	for(int i=0;i<n;i++){
		getline(cin,s);
		if(s[0]>='0' && s[0]<='9'){
			int t=0;
			for(int i=0;i<s.length();i++){
				t=t*10+(s[i]-'0');
			}
			if(t/13) cout<<s2[t/13];
			if(t/13 && t%13) cout<<' ';
			if(t%13) cout<<s1[t%13];
			if(t==0) cout<<"tret";
			cout<<endl;
		}
		else{
			string ts;
			int t=0;
			if(s.length()>5){
				ts=s.substr(0,3);
				for(int i=0;i<13;i++){
					if(ts==s2[i]){
						t+=i*13;
						break;
					}
				}
				ts=s.substr(4,s.length()-4);
				for(int i=0;i<13;i++){
					if(ts==s1[i]){
						t+=i;
						break;
					}
				}
			}
			else{
				for(int i=0;i<13;i++){
					if(s==s2[i]){
						t+=i*13;
						break;
					}
				}
				for(int i=0;i<13;i++){
					if(s==s1[i]){
						t+=i;
						break;
					}
				}
			}
			cout<<t<<endl;
		}
	}
}
