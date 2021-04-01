#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head, ListNode* pre)
{
    if (head == nullptr)
    {
        return pre;
    }
    ListNode* next = head->next;
    head->next = pre;
    return reverseList(next, head);
}

ListNode* reverseList(ListNode* head) {
    return reverseList(head, nullptr);
}

int main()
{
    int n;
    cin >> n;
    ListNode* head = new ListNode();
    ListNode* thead = head;
    cin >> thead->val;
    for (int i = 1; i < n; i++)
    {
        thead->next = new ListNode();
        thead = thead->next;
        cin >> thead->val;
    }
    thead = reverseList(head);
    while (thead)
    {
        cout << thead->val << " ";
        thead = thead->next;
    }
    cout << endl;
    return 0;
}