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

// 3.2
ListNode* merge(ListNode* l1, ListNode* l2)
{
    if (!l1)
    {
        return l2;
    }
    if (!l2)
    {
        return l1;
    }
    if (l1->val > l2->val)
    {
        swap(l1, l2);
    }
    ListNode *ans = l1, *tans = l1;
    l1 = l1->next;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            tans->next = l1;
            l1 = l1->next;
        }
        else
        {
            tans->next = l2;
            l2 = l2->next;
        }
        tans = tans->next;
    }
    tans->next = l1 ? l1 : l2;
    return ans;
}

ListNode* cut(ListNode* p, int n)
{
    while (--n && p)
    {
        p = p->next;
    }
    if (!p)
    {
        return nullptr;
    }
    ListNode* next = p->next;
    p->next = nullptr;
    return next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
    {
        return head;
    }
    ListNode* dummyHead = new ListNode();
    dummyHead->next = head;
    ListNode* p = head;
    int n = 0;
    while (p)
    {
        p = p->next;
        n++;
    }
    for (int i = 1; i <= n; i *= 2)
    {
        p = dummyHead->next;
        ListNode* tail = dummyHead;
        while (p)
        {
            ListNode* left = p;
            ListNode* right = cut(left, i);
            p = cut(right, i);
            tail->next = merge(left, right);
            while (tail->next)
            {
                tail = tail->next;
            }
        }
    }
    return dummyHead->next;
}