#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[20];
	gets(str);
	for(int i=strlen(str)-1;i>0;i--){
		cout<<str[i]<<" ";
	}
	cout<<str[0]<<endl;
	return 0;
}
