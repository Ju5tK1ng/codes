#include<bits/stdc++.h>
using namespace std;
int a[3][3],n;
int main(){
	char jia,yi;
	cin>>n;
	while(n--){
		cin>>jia>>yi;
		if(jia==yi){
			a[0][1]++;
		}
		else if(jia=='C' && yi=='J'){
			a[0][0]++;
			a[1][1]++;
		}
		else if(jia=='J' && yi=='B'){
			a[0][0]++;
			a[1][2]++;
		}
		else if(jia=='B' && yi=='C'){
			a[0][0]++;
			a[1][0]++;
		}
		else if(jia=='C' && yi=='B'){
			a[0][2]++;
			a[2][0]++;
		}
		else if(jia=='J' && yi=='C'){
			a[0][2]++;
			a[2][1]++;	
		}
		else{
			a[0][2]++;
			a[2][2]++;
		}
	}
	cout<<a[0][0]<<' '<<a[0][1]<<' '<<a[0][2]<<endl;
	cout<<a[0][2]<<' '<<a[0][1]<<' '<<a[0][0]<<endl;
	if(a[1][0]>=a[1][1] && a[1][0]>=a[1][2]){
		cout<<"B ";
	}
	else if(a[1][1]>=a[1][2]){
		cout<<"C ";
	}
	else{
		cout<<"J ";
	}
	if(a[2][0]>=a[2][1] && a[2][0]>=a[2][2]){
		cout<<"B"<<endl;
	}
	else if(a[2][1]>=a[2][2]){
		cout<<"C"<<endl;
	}
	else{
		cout<<"J"<<endl;
	}
	return 0;
}
