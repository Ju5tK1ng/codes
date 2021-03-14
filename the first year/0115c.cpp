#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,p=0,d=0;
	cin>>n;
	char a[10];
	gets(a);
	while(n--){
		gets(a);
		string b=a;
		int age=0;
		if(a[0]<='9' && a[0]>='0'){
			for(int i=0;i<strlen(a);i++){
				age=a[i]-'0'+age*10;
			}
			if(age<18) p++;
		}
		else if(b=="ABSINTH" || b=="BEER" || b=="BRANDY" || b=="CHAMPAGNE" || b=="GIN" || b=="RUM" || 
				b=="SAKE" || b=="TEQUILA" || b=="VODKA" || b=="WHISKEY" || b=="WINE"){
			d++;
		}
	}
	cout<<p+d<<endl;
	return 0;
}
