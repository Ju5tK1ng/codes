#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
private:
    Node *pre, *head;
    void inOrder(Node* node)
    {
        if (!node)
        {
            return;
        }
        inOrder(node->left);
        if (pre)
        {
            pre->right = node;
            node->left = pre;
        }
        else
        {
            head = node;
        }
        pre = node;
        inOrder(node->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
        {
            return root;
        }
        inOrder(root);
        pre->right = head;
        head->left = pre;
        return head;
    }
};
