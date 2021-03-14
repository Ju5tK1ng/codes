#include<bits/stdc++.h>
using namespace std;
int main(){
	while(true){
		int t;
		cout<<"Input an option:\n0.quit\n1.add\n2.sub\n3.mul\n4.div\n";
		cin>>t;
		switch(t){
			case 0:
				return 0;
			case 1:
				cout<<"add"<<endl;
				break;
			case 2:
				cout<<"sub"<<endl;
				break;
			case 3:
				cout<<"mul"<<endl;
				break;
			case 4:
				cout<<"div"<<endl;
				break;
			default:
				cout<<"error"<<endl;
		}
	}
}
