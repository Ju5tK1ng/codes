#include<bits/stdc++.h>
using namespace std;
int main(){
	int* p=new int[10];
	cout<<p<<" "<<*p<<" "<<p[2]<<" "<<&p[2]<<endl;
	delete[] p;
	return 0;
}
