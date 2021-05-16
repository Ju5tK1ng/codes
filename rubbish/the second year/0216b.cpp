#include<bits/stdc++.h>
using namespace std;
const int maxn=150;
stack<int> ope;
stack<int> num;
struct Operator{
	int isp,icp;
}o[maxn];
char e[maxn];
char a[]={'+','-','*','/','='};
bool find(char t){
	for(int i=0;i<strlen(a);i++){
		if(t==a[i]) return true;
	}
	return false;
}
int main(){
	o['+'].isp=o['+'].icp=12;
	o['-'].isp=o['-'].icp=12;
	o['*'].isp=o['*'].icp=13;
	o['/'].isp=o['/'].icp=13;
	o['='].isp=o['='].icp=2;
	cin>>e;
	for(int i=0;i<strlen(e);i++){
		if(find(e[i])){
			if(e[i]=='/' && e[i+1]=='0'){
				cout<<"ERROR"<<endl;
				break;
			}
			while(!ope.empty() && o[ope.top()].isp>=o[e[i]].icp){
				int tnum=num.top();
				num.pop();
				int tope=ope.top();
				ope.pop();
				if(tope=='+') tnum=num.top()+tnum;
				else if(tope=='-') tnum=num.top()-tnum;
				else if(tope=='*') tnum=num.top()*tnum;
				else tnum=num.top()/tnum;
				num.pop();
				num.push(tnum);
			}
			ope.push(e[i]);
		}
		else{
			int t=0;
			for(;!find(e[i]);i++){
				t=t*10+(e[i]-'0');
			}
			i--;
			num.push(t);
		}
	}
	cout<<num.top()<<endl;
	return 0;
}
