#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Comp{
    bool operator() (ListNode* l1, ListNode* l2)
    {
        return l1->val < l2->val;
    }
};

// 1.1
// struct Comp{
//     bool operator() (ListNode* l1, ListNode* l2)
//     {
//         return l1->val > l2->val;
//     }
// };

ListNode* sortList(ListNode* head) {
    priority_queue<ListNode*, vector<ListNode*>, Comp> q;
    while (head)
    {
        q.push(head);
        head = head->next;
    }
    while (!q.empty())
    {
        q.top()->next = head;
        head = q.top();
        q.pop();
    }
    return head;
    // 1.1
    // head = new ListNode();
    // ListNode* cur = head;
    // while (!q.empty())
    // {
    //     cur->next = q.top();
    //     cur = cur->next;
    //     q.pop();
    // }
    // cur->next = nullptr;
    // return head->next;
}