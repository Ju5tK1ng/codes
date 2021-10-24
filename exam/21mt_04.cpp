#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct ListNode* deleteNode(struct ListNode* ln, int value)
{
    ListNode *dummyHead = new ListNode();
    dummyHead->next = ln;
    ln = dummyHead;
    while (ln->next)
    {
        if (ln->next->val == value)
        {
            ln->next = ln->next->next;
        }
        else
        {
            ln = ln->next;
        }
    }
    return dummyHead->next;
}

int main()
{
    ListNode *head = new ListNode(3), *temp = head;
    for(int i = 0; i < 5; i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    head = deleteNode(head, 3);
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
