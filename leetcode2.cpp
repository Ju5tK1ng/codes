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