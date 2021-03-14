#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1010;
double x[maxn];
double y[maxn];
double lhs[maxn];
double rhs[maxn];
int main(){
	int cnt=0;
	double r,n;
	while(cin>>n>>r){
		if(n==0 && r==0) break;
		int ok=1;
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i];
			if(y[i]>r) ok=0;
		}
		if (!ok){
			cout<<"Case "<<++cnt<<": -1"<<endl;
			continue;
		}
		double t;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(x[i]>x[j]){
					swap(x[i],x[j]);
					swap(y[i],y[j]);
				}
			}
		}
		for(int i=0;i<n;i++){
			double dx=sqrt(r*r-y[i]*y[i]);
			lhs[i]=x[i]-dx;
			rhs[i]=x[i]+dx;
		}
		t=rhs[0];
		int num=1;
		for(int i=0;i<n-1;i++){
			if(lhs[i+1]>t){
				t=rhs[i+1];
				num++;
			}else if(rhs[i+1]<t){
				t=rhs[i+1];
			}
		}
		cout<<"Case "<<++cnt<<": "<<num<<endl;
	}
	return 0;
}
