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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1)
    {
        return l2;
    }
    if (!l2)
    {
        return l1;
    }
    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

int main()
{
    int n;
    cin >> n;
    ListNode* head1 = new ListNode();
    ListNode* head2 = new ListNode();
    ListNode* thead = head1;
    cin >> thead->val;
    for (int i = 1; i < n; i++)
    {
        thead->next = new ListNode();
        thead = thead->next;
        cin >> thead->val;
    }
    thead = head2;
    cin >> thead->val;
    for (int i = 1; i < n; i++)
    {
        thead->next = new ListNode();
        thead = thead->next;
        cin >> thead->val;
    }
    thead = mergeTwoLists(head1, head2);
    while (thead)
    {
        cout << thead->val << " ";
        thead = thead->next;
    }
    cout << endl;
    return 0;
}