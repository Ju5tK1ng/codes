#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *formatList(ListNode *head)
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        int cnt = 0;
        while (head && head->next)
        {
            if (cnt != 0)
            {
                // cout << head->val << endl;
                ListNode* next = head->next->next;
                head->next->next = dummyHead->next;
                dummyHead->next = head->next;
                head->next = next;
            }
            head = head->next;
            cnt++;
        }
        return dummyHead->next;
    }
};