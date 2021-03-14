#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	char n[11];
	gets(n);
	int len=strlen(n);
	for(int i=len-1;i>=0;i--){
		if(i==0 && n[i]=='1'){
			cout<<"YES"<<endl;
			break;	
		}
		if(i==1){
			if((n[i]=='1' || n[i]=='4') && n[i-1]=='1'){
				cout<<"YES"<<endl;
				break;
			}
			else{
				cout<<"NO"<<endl;
				break;
			}
		}
		else if(n[i]=='1'){
			continue;
		}
		else if(n[i]=='4' && (n[i-1]=='1' || n[i-2]=='1')){
			continue;
		}
		else {
			cout<<"NO"<<endl;
			break;
		}
	}
    return 0;
}
