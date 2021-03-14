#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int ans=0,a[5],figure=-1;
	cin>>s;
	for(int i=0;i<s.length();i++){
		ans+=s[i]-'0';
	}
	for(int i=0;ans!=0;i++){
		a[i]=ans%10;
		ans/=10;
		figure++;
	}
	for(int i=figure;i>=0;i--){
		switch(a[i]){
			case 0:cout<<"ling";break;
			case 1:cout<<"yi";break;
			case 2:cout<<"er";break;
			case 3:cout<<"san";break;
			case 4:cout<<"si";break;
			case 5:cout<<"wu";break;
			case 6:cout<<"liu";break;
			case 7:cout<<"qi";break;
			case 8:cout<<"ba";break;
			case 9:cout<<"jiu";break;
			default:break;
		}
		if(i!=0) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
