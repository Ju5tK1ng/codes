#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if (l1)
        {
            l1->next = merge(l2, l1->next);
        }
        return l1;
    }

    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *pre = nullptr, *next = slow->next;
        slow->next = nullptr;
        slow = next;
        while (slow)
        {
            next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        head = merge(head, pre);
    }
};

// 2.0
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *pre = nullptr, *next = slow->next;
        slow->next = nullptr;
        slow = next;
        while (slow)
        {
            next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        while(pre)
        {
            next = head->next;
            head->next = pre;
            head = next;
            next = pre->next;
            pre->next = head;
            pre = next;
        }
        // 2.1
        // while (pre)
        // {
        //     next = pre->next;
        //     pre->next = head->next;
        //     head->next = pre;
        //     head = pre->next;
        //     pre = next;
        // }
    }
};