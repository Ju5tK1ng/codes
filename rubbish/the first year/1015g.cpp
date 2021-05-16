#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n, i, len,count;
    char s[100];
    cin>>n;
    gets(s);
    while(n--){
        count =0;
        gets(s);
        len = strlen(s);
        for(i=0; i<len; i++){
            if(s[i]<0){
            	count++;
			}
        }
        cout<<count/2<<endl;
    }
    return 0;
}
