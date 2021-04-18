#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    // ListNode() : val(0), next(nullptr) {}
    // ListNode(int x) : val(x), next(nullptr) {}
    // ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* solve(ListNode* S) {
        ListNode *pre = S, *pnext, *next, *head = S;
        while (S->next)
        {
            pnext = pre->next;
            next = S->next;
            while (next != S && pnext->val == next->val)
            {
                pnext = pnext->next ? pnext->next : head;
                next = next->next ? next->next : head;
            }
            if (pnext->val > next->val)
            {
                pre = S;
            }
            S = S->next;
        }
        pnext = pre->next;
        while (pnext->next)
        {
            pnext = pnext->next;
        }
        pnext->next = head;
        head = pre->next;
        pre->next = nullptr;
        return head;
    }
};