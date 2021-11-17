#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummyHead = new Node(-1), *oldCur = head, *newCur = dummyHead;
        unordered_map<Node*, Node*> um;
        while (oldCur)
        {
            newCur->next = new Node(oldCur->val);
            newCur = newCur->next;
            um[oldCur] = newCur;
            oldCur = oldCur->next;
        }
        oldCur = head;
        newCur = dummyHead->next;
        while (oldCur)
        {
            newCur->random = um[oldCur->random];
            newCur = newCur->next;
            oldCur = oldCur->next;
        }
        return dummyHead->next;
    }
};
