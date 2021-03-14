#include<bits/stdc++.h>
using namespace std;
const int maxn=150;
stack<int> s;
struct Operator{
	int isp,icp;
}o[maxn];
char e[maxn];
char a[]={'(',')','+','-','*','/','%'};
bool find(char ope){
	for(int i=0;i<strlen(a);i++){
		if(ope==a[i]) return true;
	}
	return false;
}
int main(){
	o['('].isp=0,o['('].icp=20;
	o[')'].isp=o[')'].icp=0;
	o['+'].isp=o['+'].icp=12;
	o['-'].isp=o['-'].icp=12;
	o['*'].isp=o['*'].icp=13;
	o['/'].isp=o['/'].icp=13;
	o['%'].isp=o['%'].icp=13;
	cin>>e;
	for(int i=0;i<strlen(e);i++){
		if(e[i]==')'){
			while(s.top()!='('){
				cout<<char(s.top());
				s.pop();
			}
			s.pop();
		}
		else if(find(e[i])){
			while(!s.empty() && o[s.top()].isp>=o[e[i]].icp){
				cout<<char(s.top());
				s.pop();
			}
			s.push(e[i]);
		}
		else cout<<char(e[i]);
	}
	while(!s.empty()){
		cout<<char(s.top());
		s.pop();
	}
	cout<<endl;
	return 0;
}
