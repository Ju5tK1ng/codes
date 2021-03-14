#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c,ans=0,ma,mi,mid;
    cin>>a>>b>>c;
    ma=max(max(a,b),c);
    mi=min(min(a,b),c);
    mid=a+b+c-ma-mi;
    if(ma>=mid+mi){
    	ans=ma+1-mi-mid;
	}
	cout<<ans<<endl;
    return 0;
}
