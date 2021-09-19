#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        map<int, short> m;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        while (head)
        {
            m[head->val]++;
            head = head->next;
        }
        head = dummyHead->next;
        while (head)
        {
            for (auto& p : m)
            {
                if (p.second != 0)
                {
                    head->val = p.first;
                    p.second--;
                    head = head->next;
                }
            }
        }
        return dummyHead->next;
    }
};
