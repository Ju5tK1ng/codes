#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 3.0
ListNode* merge_sort(ListNode* head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    head = merge_sort(head);
    mid = merge_sort(mid);
    ListNode* ans = new ListNode();
    ListNode* tans = ans;
    while (head && mid)
    {
        if (head->val <= mid->val)
        {
            tans->next = head;
            head = head->next;
        }
        else
        {
            tans->next = mid;
            mid = mid->next;
        }
        tans = tans->next;
    }
    tans->next = head ? head : mid;
    return ans->next;
}
// 3.1
ListNode* merge_sort(ListNode* head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    head = merge_sort(head);
    mid = merge_sort(mid);
    if (head->val > mid->val)
    {
        swap(head, mid);
    }
    ListNode *ans = head, *tans = head;
    head = head->next;
    while (head && mid)
    {
        if (head->val <= mid->val)
        {
            tans->next = head;
            head = head->next;
        }
        else
        {
            tans->next = mid;
            mid = mid->next;
        }
        tans = tans->next;
    }
    tans->next = head ? head : mid;
    return ans;
}

ListNode* sortList(ListNode* head) {
    return merge_sort(head);
}