#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 2.0
ListNode* quick_sort(ListNode* head, ListNode* tail)
{
    if (head == tail || head->next == tail)
    {
        return head;
    }
    ListNode *fast = head, *slow = head;
    while (fast->next != tail && fast->next->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* next = slow->next;
    slow->next = slow->next->next;
    next->next = head;
    head = next;
    ListNode *i = head, *j = head, *pivot = head, *cur = head->next;
    while (cur != tail)
    {
        ListNode* next = cur->next;
        if (pivot->val <= cur->val)
        {
            j->next = cur;
            j = cur;
        }
        else
        {
            cur->next = i;
            i = cur;
        }
        cur = next;
    }
    j->next = tail;
    head = quick_sort(i, pivot);
    pivot->next = quick_sort(pivot->next, tail);
    return head;
}

ListNode* sortList(ListNode* head) {
    return quick_sort(head, nullptr);
}