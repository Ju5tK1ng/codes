#include<bits/stdc++.h>
using namespace std;
class LinkNode{
	public:
		int val;
		LinkNode* next;
};
void Insertion_sort(LinkNode* &L){
	LinkNode* i=L->next->next;
	L->next->next=NULL;
	while(i!=NULL){
		LinkNode* temp=i->next;
		LinkNode* j=L;
		while(j->next!=NULL && j->next->val<i->val){
			j=j->next;
		}
		i->next=j->next;
		j->next=i;
		i=temp;
	}
}
int main(){
	int n;
	LinkNode* L=(LinkNode *)malloc(sizeof(LinkNode)),*p,*r;
	L->next=NULL;
	r=L;
	cin>>n;
	for(int i=0;i<n;i++){
		p=(LinkNode *)malloc(sizeof(LinkNode));
		cin>>p->val;
		r->next=p;
		r=r->next;
	}
	r->next=NULL;
	Insertion_sort(L);
	p=L->next;
	while(p!=NULL){
		cout<<p->val<<' ';
		p=p->next;
	}
	cout<<endl;
	return 0;
}
