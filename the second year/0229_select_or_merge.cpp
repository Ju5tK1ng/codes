#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn],s[maxn],n;
int issame(){
	for(int i=0;i<n;i++){
		if(a[i]!=s[i]) return 0;
	}
	return 1;
}
void insertion_sort(){
	int i=1;
	while(a[i-1]<=a[i]) i++;
	if(i<n-1) sort(a,a+i+1);
}
int merge_sort(){
	for(int i=2;i/2<n;i*=2){
		if(i!=2 && issame()==1){
			for(int j=0;j<n;j+=i) sort(a+j,a+min(j+i,n));
			return 1;
		}
		for(int j=0;j<n;j+=i) sort(s+j,s+min(j+i,n));
	}
	return 0;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(merge_sort()==1){
		cout<<"Merge Sort"<<endl;
	}
	else{
		cout<<"Insertion Sort"<<endl;
		insertion_sort();
	}
	for(int i=0;i<n;i++){
		if(i!=n-1) cout<<a[i]<<" ";
		else cout<<a[i]<<endl;
	}
	return 0;
}
