#include<bits/stdc++.h>
using namespace std;
struct Student{
	string name;
	string number;
	int grade;
	bool operator <(const Student& t)const{
		return grade<t.grade;
	}
}a[10000];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].name>>a[i].number>>a[i].grade;
	}
	sort(a,a+n);
	cout<<a[n-1].name<<' '<<a[n-1].number<<endl<<a[0].name<<' '<<a[0].number<<endl;
	return 0;
}
