#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 1.1
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    do
    {
        if (!fast || !fast->next)
        {
            return nullptr;
        }
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    fast = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
int main()
{
    int n, t, pos;
    cin >> n;
    cin >> t;
    ListNode *head = new ListNode(t);
    ListNode *curNode = head;
    for (int i = 1; i < n; i++)
    {
        cin >> t;
        curNode->next = new ListNode(t);
        curNode = curNode->next;
    }
    cin >> pos;
    if (pos != -1)
    {
        ListNode *cycleStart = head;
        curNode->next = cycleStart;
        for (int i = 0; i < pos; i++)
        {
            cycleStart = cycleStart->next;
            curNode->next = cycleStart;
        }
    }
    cout << detectCycle(head)->val << endl;
    return 0;
}