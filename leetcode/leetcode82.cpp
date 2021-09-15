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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode *cur = dummyHead;
        while (cur->next)
        {
            head = cur->next;
            while (head->next && head->next->val == cur->next->val)
            {
                head = head->next;
            }
            if (head == cur->next)
            {
                cur = cur->next;
            }
            else
            {
                cur->next = head->next;
            }
        }
        return dummyHead->next;
    }
};
