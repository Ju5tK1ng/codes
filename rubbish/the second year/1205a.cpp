#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
int main(){
	node *head;
	node *p1,*p2;
	p1=(node *)malloc(sizeof(node));
	p2=(node *)malloc(sizeof(node));
	(*p1).data=1;
	p2->data=2;
	p1->next=p2;
	p2->next=NULL;
	head=p1;
	cout<<p1->data<<endl<<(*p2).data<<endl;
	cout<<head->next->data<<endl;
	return 0;
}
