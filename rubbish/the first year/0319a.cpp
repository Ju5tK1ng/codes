#include<iostream>
using namespace std;
void bubbleSort(int len,int seq[]);
int main(){
	int seq[10]={3,9,1,4,7,6,5,8,2,0};
	int len=sizeof(seq)/sizeof(int);
	bubbleSort(len,seq);
	return 0;
}
void bubbleSort(int len,int seq[]){
	for(int i=0;i<len-1;i++){
		for(int j=i+1;j<len-1;j++){
			if(seq[i]<seq[j]) swap(seq[i],seq[j]);
		}
	}
	cout<<"Sorted:[";
	for(int i=0;i<len;i++){
		cout<<seq[i];
		if(i==len-1) cout<<"]"<<endl;
		else cout<<",";
	}
}
