#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int carry;
public:
    void add(ListNode* l1, ListNode* l2, int cnt)
    {
        if (!l1)
        {
            return;
        }
        if (cnt > 0)
        {
            add(l1->next, l2, cnt - 1);
            l1->val += carry;
            carry = l1->val / 10;
            l1->val %= 10;
        }
        else
        {
            add(l1->next, l2->next, cnt);
            l1->val += l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int m = 0, n = 0;
        carry = 0;
        ListNode *head1 = l1, *head2 = l2;
        while (l1)
        {
            m++;
            l1 = l1->next;
        }
        while (l2)
        {
            n++;
            l2 = l2->next;
        }
        if (m < n)
        {
            swap(head1, head2);
            swap(m, n);
        }
        add(head1, head2, m - n);
        if (carry == 1)
        {
            head1 = new ListNode(1, head1);
        }
        return head1;
    }
};
