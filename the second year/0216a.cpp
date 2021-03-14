#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
    char Data;
    struct treeNode* left;
    struct treeNode* right;
};

typedef struct treeNode* Node;
int N=0;
Node createTree(char *zfsz){
    if(*(zfsz+N)=='#'){
        N++;
        return NULL;
    }
    Node root=(Node)malloc(sizeof(struct treeNode));
    root->Data=*(zfsz+N);
    N++;
    root->left=createTree(zfsz);
    root->right=createTree(zfsz);
    return root;
}
void zhongxubianli(Node root)
{
    if(root==NULL)return;
    zhongxubianli(root->left);
        cout<<root->Data;
    zhongxubianli(root->right);
}
int searchNode(Node Root){
    if(Root==NULL)return 0;
    if(Root->left==NULL&&Root->right==NULL)
        return searchNode(Root->left)+searchNode(Root->right)+1;
    else
        return searchNode(Root->left)+searchNode(Root->right);
}
int main()
{
    char zfsz[101];
	while(scanf("%s",zfsz) != EOF)
    {
        Node Root=createTree(zfsz);
        zhongxubianli(Root);
        N=0;
        cout<<endl;
        cout<<searchNode(Root)<<endl;
    }
    return 0;
}
