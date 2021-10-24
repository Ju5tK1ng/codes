#include <bits/stdc++.h>
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
        return l1->val > l2->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Comp> q;
    for (ListNode* list : lists)
    {
        if (list)
        {
            q.push(list);
        }
    }
    ListNode* dummyHead = new ListNode(0), *cur =  dummyHead;
    while (!q.empty())
    {
        cur->next = q.top();
        q.pop();
        cur = cur->next;
        if (cur->next)
        {
            q.push(cur->next);
        }
    }
    return dummyHead->next;
}
