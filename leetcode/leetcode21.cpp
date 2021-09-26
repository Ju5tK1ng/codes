#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1.0
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(), *t = dummyHead;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                t->next = l1;
                l1 = l1->next;
            }
            else
            {
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }
        t->next = l1 ? l1 : l2;
        return dummyHead->next;
    }
};

// 2.0
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
