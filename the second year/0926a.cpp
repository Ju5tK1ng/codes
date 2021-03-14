#include<bits/stdc++.h>
using namespace std;
struct monomial{
	float n;
	int r;
};
monomial a[55],b[55];
int main(){
	string p;
	char c;
	int t;
	//輸入第一個多項式后在係數為1的項前面加上數字1 
	cin>>p;
	for(int i=0;i<p.length();i++){
		if(p[i]=='x' && (i==0 || p[i-1]=='+' || p[i-1]=='-'))
		p.insert(i,"1");
	}
	//讀取第一個多項式 
	istringstream s1(p);
	t=0;
	while(s1){
		s1>>a[t].n>>c>>c>>a[t].r;
		t++;
	}
	//輸入第二個多項式后在係數為1的項前面加上數字1
	cin>>p;
	for(int i=0;i<p.length();i++){
		if(p[i]=='x' && (i==0 || p[i-1]=='+' || p[i-1]=='-'))
		p.insert(i,"1");
	}
	//讀取第二個多項式 
	istringstream s2(p);
	t=0;
	while(s2){
		s2>>b[t].n>>c>>c>>b[t].r;
		t++;
	}
	//多項式相加，用t來代表指數最大項的指數
	t=-1;
	for(int i=0;i<=50;i++){
		for(int j=0;j<=50;j++){
			if(a[i].r=b[j].r){
				a[i].n+=b[j].n;
				
			}
		}
		a[i]+=b[i];
		if(a[i]!=0){
			t=i;
		}
	}
	//輸出結果
	for(int i=50;i>=0;i--){
		if(a[i]!=0){
			if(a[i]>0){
				if(i!=t) cout<<'+';
				if(a[i]!=1 || i==0) cout<<a[i];
			}
			else{
				cout<<'-'; 
				if(a[i]!=-1 || i==0) cout<<-a[i];
			}
			if(i!=0) cout<<"x^"<<i;
		}
	}
	//如果t==-1，代表相加結果為0，則輸出0
	if(t==-1) cout<<0;
	cout<<endl;
	return 0;
}
