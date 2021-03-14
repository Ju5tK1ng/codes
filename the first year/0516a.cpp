#include<bits/stdc++.h>
using namespace std;
char &get_val(string &str,string::size_type ix)
{
    return str[ix];
}
int main() {
	string s("123456");
	cout<<s<<endl;
	get_val(s,0)='a';
	cout<<s<<endl;
	return 0;
}      
