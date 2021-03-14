#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[10];
	int m,k,cnt=0;
	cin>>str>>k;
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='3') cnt++;
		m=m*10+(str[i]-'0');
	}
	if(m%19==0&&cnt==k) cout<<"YES";
	else cout<<"NO";
	return 0;
}
