#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn],s[maxn];
void insertion_sort(int n){
	int t,i=2;
	while(a[i-1]<=a[i]) i++;
	t=a[i];
	for(;a[i-1]>t;i--){
		a[i]=a[i-1];
	}
	a[i]=t;
}
void bottom_up(int i,int len){
	int t=i;
	if(i*2<len && a[t]<a[i*2]) t=i*2;
	if(i*2+1<len && a[t]<a[i*2+1]) t=i*2+1;
	if(t!=i){
		swap(a[i],a[t]);
		bottom_up(t,len);
	}
}
void heap_sort(int n){
	int i=n;
	while(a[i]>a[1]) i--;
	pop_heap(a+1,a+i+1);
//	swap(a[i],a[1]);
//	bottom_up(1,i);
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]<a[2]){
		cout<<"Insertion Sort"<<endl;
		insertion_sort(n);
	}
	else{
		cout<<"Heap Sort"<<endl;
		heap_sort(n);
	}
	for(int i=1;i<=n;i++){
		if(i!=n) cout<<a[i]<<" ";
		else cout<<a[i]<<endl;
	}
	return 0;
}
