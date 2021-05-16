#include<iostream>
using namespace std;
double n,a[100],b[4];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<=18) b[0]++;
		else if(a[i]<=35) b[1]++;
		else if(a[i]<=60) b[2]++;
		else b[3]++;
	}
	n/=100;
	printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n%.2lf%%\n",b[0]/n,b[1]/n,b[2]/n,b[3]/n);
	return 0;
}
