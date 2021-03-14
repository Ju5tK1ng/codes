#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
double p[2][maxn];
int sex[maxn],n,m;
vector <int> pic[maxn],v[2];
int read_num(){
	char c[6];
	cin>>c;
	int a=abs(atoi(c));
	if(c[0]!='-') sex[a]=1;
	return a;
}
void write_num(int a,int b){
	if(sex[a]==-1) cout<<'-';
	cout<<a<<' ';
	if(sex[b]==-1) cout<<'-';
	cout<<b<<endl;
}
void count_qmd(int i,int num,int x){
	if(find(pic[i].begin(),pic[i].end(),num)!=pic[i].end()){
		int k=pic[i].size();
		for(int j=0;j<k;j++){
			if(sex[num]*sex[pic[i][j]]<0) p[x][pic[i][j]]-=1.0/k;
		}
	}
}
double search_qmd(int x){
	double minn=0;
	for(int i=0;i<n;i++){
		if(p[x][i]<minn){
			minn=p[x][i];
			v[x].clear();
		}
		if(p[x][i]==minn) v[x].push_back(i);
	}
	sort(v[x].begin(),v[x].end());
	return minn;
}
int main(){
	memset(sex,-1,sizeof(sex));
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			pic[i].push_back(read_num());
		}
	}
	int a,b;
	a=read_num();
	b=read_num();
	for(int i=0;i<m;i++){
		count_qmd(i,a,0);
		count_qmd(i,b,1);
	}
	double mina=search_qmd(0);
	double minb=search_qmd(1);
	if(p[0][b]==mina && p[1][a]==minb) write_num(a,b);
	else{
		for(int i=0;i<v[0].size();i++){
			write_num(a,v[0][i]);
		}
		for(int i=0;i<v[1].size();i++){
			write_num(b,v[1][i]);
		}
	}
	return 0;
}
