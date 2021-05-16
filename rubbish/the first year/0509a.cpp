#include<bits/stdc++.h>
using namespace std;
void change(int& k){
	k=4;
}
void change2(int* o){
	*o=5;
}
int main(){
	int i=1;
	int& j=i;
	j=2;
	cout<<i<<" "<<&i<<endl<<j<<" "<<&j<<endl;
	i=3;
	cout<<i<<" "<<&i<<endl<<j<<" "<<&j<<endl;
	change(i);
	cout<<i<<" "<<&i<<endl;
	change2(&i);
	cout<<i<<" "<<&i<<endl;
	return 0;
}
