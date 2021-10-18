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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = l1, *head2 = l2;
        l1->val += l2->val;
        int carry = l1->val / 10;
        l1->val = l2->val = l1->val % 10;
        while (l1->next && l2->next)
        {
            l1 = l1->next;
            l2 = l2->next;
            l1->val += l2->val + carry;
            carry = l1->val / 10;
            l1->val = l2->val = l1->val % 10;
        }
        if (l2->next)
        {
            head1 = head2;
            l1 = l2;
        }
        while (l1->next && carry)
        {
            l1 = l1->next;
            l1->val += carry;
            carry = l1->val / 10;
            l1->val %= 10;
        }
        if (carry)
        {
            l1->next = new ListNode(1);
        }
        return head1;
    }
};

// 1.1
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = l1, *tail;
        int carry = 0;
        while (l1)
        {
            l1->val += carry;
            if (l2)
            {
                l1->val += l2->val;
            }
            carry = l1->val / 10;
            l1->val %= 10;
            if (!l1->next)
            {
                if (l2)
                {
                    l1->next = l2->next;
                    l2 = nullptr;
                }
            }
            tail = l1;
            l1 = l1->next;
            if (l2)
            {
                l2 = l2->next;
            }
        }
        if (carry)
        {
            tail->next = new ListNode(1);
        }
        return head;
    }
};

// 2.0
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(), *head = dummyHead;
        int carry = 0, n1, n2;
        while (l1 || l2)
        {
            if (l1)
            {
                n1 = l1->val;
                l1 = l1->next;
            }
            else
            {
                n1 = 0;
            }
            if (l2)
            {
                n2 = l2->val;
                l2 = l2->next;
            }
            else
            {
                n2 = 0;
            }
            head->next = new ListNode((n1 + n2 + carry) % 10);
            head = head->next;
            carry = (n1 + n2 + carry) / 10;
        }
        if (carry)
        {
            head->next = new ListNode(1);
        }
        return dummyHead->next;
    }
};
