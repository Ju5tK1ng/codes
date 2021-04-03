#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *l1 = headA, *l2 = headB;
    // int cnt = 0;
    while (l1 != l2)
    {
        // cout << ++cnt << endl;
        l1 = l1 ? l1->next : headB;
        l2 = l2 ? l2->next : headA;
    }
    return l1;
}

int main()
{
    int m, n;
    cin >> m >> n;
    ListNode* head1 = new ListNode();
    ListNode* head2 = new ListNode();
    ListNode* thead1 = head1;
    ListNode* thead2 = head2;
    cin >> thead1->val;
    for (int i = 1; i < m; i++)
    {
        thead1->next = new ListNode();
        thead1 = thead1->next;
        cin >> thead1->val;
    }
    cin >> thead2->val;
    for (int i = 1; i < n; i++)
    {
        thead2->next = new ListNode();
        thead2 = thead2->next;
        cin >> thead2->val;
    }
    thead2->next = thead1;
    for (int i = 1; i < n; i++)
    {
        thead1->next = new ListNode();
        thead1 = thead1->next;
        cin >> thead1->val;
    }
    thead2 = getIntersectionNode(head1, head2);
    if (thead2)
    {
        cout << thead2->val << endl;
    }
    else
    {
        cout << "NULL" << endl;
    }  
    return 0;
}