#include<bits/stdc++.h>
using namespace std;
struct Student{
	int num,de,cai;
	bool operator <(const Student& t)const{
		if(de+cai==t.de+t.cai && de==t.de){
			return num<t.num;
		}
		else if(de+cai==t.de+t.cai){
			return de>t.de;
		}
		else return de+cai>t.de+t.cai;
	}
};
int main(){
	Student s[100010],s1[100010],s2[100010],s3[100010],s4[100010];
	int n,l,h,c1=0,c2=0,c3=0,c4=0;
	cin>>n>>l>>h;
	for(int i=0;i<n;i++){
		cin>>s[i].num>>s[i].de>>s[i].cai;
		if(s[i].de>=h && s[i].cai>=h){
			s1[c1++]=s[i];
		}
		else if(s[i].de>=h && s[i].cai>=l){
			s2[c2++]=s[i];
		}
		else if(s[i].de>=l && s[i].cai>=l && s[i].de>=s[i].cai){
			s3[c3++]=s[i];
		}
		else if(s[i].de>=l && s[i].cai>=l){
			s4[c4++]=s[i];
		}
	}
	sort(s1,s1+c1);
	sort(s2,s2+c2);
	sort(s3,s3+c3);
	sort(s4,s4+c4);
	cout<<c1+c2+c3+c4<<endl;
	for(int i=0;i<c1;i++){
		cout<<s1[i].num<<' '<<s1[i].de<<' '<<s1[i].cai<<endl;
	}
	for(int i=0;i<c2;i++){
		cout<<s2[i].num<<' '<<s2[i].de<<' '<<s2[i].cai<<endl;
	}
	for(int i=0;i<c3;i++){
		cout<<s3[i].num<<' '<<s3[i].de<<' '<<s3[i].cai<<endl;
	}
	for(int i=0;i<c4;i++){
		cout<<s4[i].num<<' '<<s4[i].de<<' '<<s4[i].cai<<endl;
	}
	return 0;
}
