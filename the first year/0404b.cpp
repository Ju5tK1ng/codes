#include<iostream>
using namespace std;
int sum(int* begin,int* end){
	int *p=begin;
	int ans=0;
	for(int *p=begin;p!=end;p++){
		ans+=*p;
	}
	return ans;
}
int main(){
	int a[]={1,2,3,4};
	cout<<sum(a+1,a+3)<<endl;
	return 0;
}
