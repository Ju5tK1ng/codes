#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *pre = nullptr, *next;
    while (slow)
    {
        next = slow->next;
        slow->next = pre;
        pre = slow;
        slow = next;
    }
    while (pre)
    {
        if (head->val != pre->val)
        {
            return false;
        }
        pre = pre->next;
        head = head->next;
    }
    return true;
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
    cout << isPalindrome(head) << endl;
    return 0;
}