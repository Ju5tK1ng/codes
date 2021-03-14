#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t,a1=0,a2=0,a3=0,a5=0,cnt=0,a2ok=0;
	float a4=0;
	bool plus=true;
	cin>>n;
	while(n--){
		cin>>t;
		switch(t%5){
			case 0:
				if(t%2==0) a1+=t;
				break;
			case 1:
				a2ok=1;
				if(plus){
					a2+=t;
				}
				else{
					a2-=t;
				}
				plus=!plus;
				break;
			case 2:
				a3++;
				break;
			case 3:
				a4+=t;
				cnt++;
				break;
			case 4:
				a5=max(a5,t);
				break;
		}
	}
	if(a1) cout<<a1<<" ";
	else cout<<"N"<<" ";
	if(a2ok) cout<<a2<<" ";
	else cout<<"N"<<" ";
	if(a3) cout<<a3<<" ";
	else cout<<"N"<<" ";
	if(a4) printf("%.1f ",a4/cnt);
	else cout<<"N"<<" ";
	if(a5) cout<<a5<<endl;
	else cout<<"N"<<endl;
	return 0;
}
