#include<iostream>
using namespace std;
int main()
{
	double Sn;
	int k;
	cin>>k;
	for(int i=1;;i++){
		Sn+=1.0/i;
		if(Sn>k){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
