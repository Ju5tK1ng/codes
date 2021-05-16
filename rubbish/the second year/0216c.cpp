#include<bits/stdc++.h>
using namespace std;
const int maxn=150;
int ope,ans,num,ok=1;
char e[maxn];
char a[]={'+','-','*','/','='};
bool find(char t){
	for(int i=0;i<strlen(a);i++){
		if(t==a[i]) return true;
	}
	return false;
}
int main(){
	cin>>e;
	for(int i=0;i<strlen(e);i++){
		if(e[i]=='/' && e[i+1]=='0' || !(e[i]>='0' && e[i]<='9' || find(e[i]))){
				cout<<"ERROR"<<endl;
				break;
		}
		if(find(e[i])){
			if(ope=='+') ans+=num;
			else if(ope=='-') ans-=num;
			else if(ope=='*') ans*=num;
			else ans/=num;
			if(e[i]=='='){
				cout<<ans<<endl;
				break;
			}
			ope=e[i];
		}
		else{
			int t=0;
			for(;e[i]>='0' && e[i]<='9';i++){
				t=t*10+(e[i]-'0');
			}
			i--;
			num=t;
			if(ok){
				ans=num;
				ok=0;
			}
		}
	}
	return 0;
}
