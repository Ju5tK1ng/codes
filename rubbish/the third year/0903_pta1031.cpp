#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,cnt=0;
	string s;
	int a[20]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		int z=0;
		for(int j=0;j<17;j++){
			z+=(s[j]-'0')*a[j];
		}
		z%=11;
		if(z==0 && s[17]!='1' || z==1 && s[17]!='0' || z==2 && s[17]!='X' || z==3 && s[17]!='9' || z==4 && s[17]!='8' || z==5 && s[17]!='7' ||
		   z==6 && s[17]!='6' || z==7 && s[17]!='5' || z==8 && s[17]!='4' || z==9 && s[17]!='3' || z==10 && s[17]!='2'){
		   	cout<<s<<endl;
		   	cnt++;
		}
	}
	if(cnt==0) cout<<"All passed"<<endl;
	return 0;
}
