#include<bits/stdc++.h>
using namespace std;
// 2.0
struct Node {
    int val;
    int minn;
    Node* next;
    Node() : val(0), minn(0), next(nullptr) {}
    Node(int x, int y) : val(x), minn(y), next(nullptr) {}
    Node(int x, int y, Node* next) : val(x), minn(y), next(next) {}
};
class MinStack {
    Node* head;
public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if (head)
        {
            head = new Node(val, min(val, head->minn), head);
        }
        else
        {
            head = new Node(val, val);
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->minn;
    }
};