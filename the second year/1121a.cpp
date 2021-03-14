#include<iostream>
using namespace std;
int sum(int A[],int n){
	if(n<1) return 0;
	else return sum(A,n-1)+A[n-1];
}
int hailstone(int n){
	int length=1;
	while(n>1) {
		(n%2)?n=3*n+1:n/=2;
		length++;
	}
	return length;
}
int main(){
	cout<<hailstone(111)<<endl;
	return 0;
}
