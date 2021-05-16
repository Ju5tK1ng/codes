#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1.1
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* ans = new ListNode();
    ListNode* tans = ans;
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
    return ans->next;
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