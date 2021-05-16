#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	cin>>n;
	getchar();
	char a[50];
	while(n--){
		int ok=1;
		gets(a);
		for(int i=0;i<strlen(a);i++){
			if(!((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z') || (a[i]>='0' && a[i]<='9') || a[i]=='_')){
				ok=0;
				break;
			}
		}
		if(a[0]>='0' && a[0]<='9') ok=0;
		if(ok) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	} 
	return 0;
}
