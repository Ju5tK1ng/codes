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
	//ݔ���һ�����ʽ���ڂS����1���ǰ����ϔ���1 
	cin>>p;
	for(int i=0;i<p.length();i++){
		if(p[i]=='x' && (i==0 || p[i-1]=='+' || p[i-1]=='-'))
		p.insert(i,"1");
	}
	//�xȡ��һ�����ʽ 
	istringstream s1(p);
	t=0;
	while(s1){
		s1>>a[t].n>>c>>c>>a[t].r;
		t++;
	}
	//ݔ��ڶ������ʽ���ڂS����1���ǰ����ϔ���1
	cin>>p;
	for(int i=0;i<p.length();i++){
		if(p[i]=='x' && (i==0 || p[i-1]=='+' || p[i-1]=='-'))
		p.insert(i,"1");
	}
	//�xȡ�ڶ������ʽ 
	istringstream s2(p);
	t=0;
	while(s2){
		s2>>b[t].n>>c>>c>>b[t].r;
		t++;
	}
	//���ʽ��ӣ���t�����ָ�����헵�ָ��
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
	//ݔ���Y��
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
	//���t==-1��������ӽY����0���tݔ��0
	if(t==-1) cout<<0;
	cout<<endl;
	return 0;
}
