#include<bits/stdc++.h>
using namespace std;
int main(){
	string old,input;
	bool badCaps=false;
	getline(cin,old);
	getline(cin,input);
	for(int i=0;i<old.length();i++){
		if(old[i]=='+'){
			badCaps=true;
			break;
		}
	}
	for(int i=0;i<input.length();i++){
		bool ok=true;
		for(int j=0;j<old.length();j++){
			char t=input[i];
			if(input[i]>='A' && input[i]<='Z' && badCaps){
				ok=false;
				break;
			}
			if(input[i]>='a' && input[i]<='z') t=input[i]-32;
			if(t==old[j]){
				ok=false;
				break;
			}
		}
		if(ok){
			cout<<input[i];
		}
	}
	cout<<endl;
	return 0;
}
