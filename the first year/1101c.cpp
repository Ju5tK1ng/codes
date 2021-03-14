#include<iostream>
#include<cstring>
using namespace std;
int cpa(const char* s,int i,int ans)
{
	int n=strlen(s);
	for(int j=0;j<n;j++){
		if(s[(i+j)%n]<s[(ans+j)%n]) return 1;
		if(s[(i+j)%n]>s[(ans+j)%n]) return 0;
	}
	return 0;
}
int main()
{
	char s[110];
	while(cin>>s){
		int ans=0,n=strlen(s);
		for(int i=0;i<n;i++){
			if(cpa(s,i,ans)) ans=i;
		}
		for(int i=0;i<n;i++){
			putchar(s[(i+ans)%n]);
		}
		cout<<endl;
	}
	return 0;
}
