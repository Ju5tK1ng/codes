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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0, head), *pre = dummy, *next;
        for (int i = 1; i < left; i++)
        {
            pre = pre->next;
        }
        head = pre->next;
        for (int i = left; i <= right; i++)
        {
            next = head->next;
            head->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy->next;
    }
};