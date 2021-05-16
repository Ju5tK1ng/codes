#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)){
		int sum=0,x;
		stringstream ss(s);
		while(ss>>x) sum+=x;
		cout<<sum<<endl;
	}
	return 0;
}
