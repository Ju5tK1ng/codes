#include<bits/stdc++.h>
using namespace std;
stack<int> s1;
stack<int> s2;
int main(){
	int n1,n2,n,t,cnt=0;
	cin>>n1>>n2;
	n=min(n1,n2);
	char ope;
	while(cin>>ope){
		if(ope=='T') break;
		if(ope=='A'){
			cin>>t;
			if(cnt==n && !s2.empty()) cout<<"ERROR:Full"<<endl;
			else{
				if(cnt==n && s2.empty()){
					while(cnt){
						s2.push(s1.top());
						s1.pop();
						cnt--; 
					}
				}
				s1.push(t);
				cnt++;
			}
		}
		if(ope=='D'){
			if(!s1.empty() && s2.empty()){
				while(cnt){
					s2.push(s1.top());
					s1.pop();
					cnt--;
				}
			}
			if(!s2.empty()){
				cout<<s2.top()<<endl;
				s2.pop();
			}
			else cout<<"ERROR:Empty"<<endl;
		}
	}
	return 0; 
}
