#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* nextHead)
    {
        ListNode *pre = nullptr, *next;
        while (head != nextHead)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyHead = new ListNode(), *preTail = dummyHead, *nextHead = head;
        int cnt = 0;
        while (nextHead != nullptr)
        {
            nextHead = nextHead->next;
            cnt++;
            if (cnt % k == 0)
            {
                preTail->next = reverseList(head, nextHead);
                preTail = head;
                head = nextHead;
            }
        }
        preTail->next = head;
        return dummyHead->next;
    }
};

// 2.0
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *preTail = head, *nextHead = head;
        for (int i = 0; i < k; i++)
        {
            if (nextHead == nullptr)
            {
                return head;
            }
            nextHead = nextHead->next;
        }
        ListNode *pre, *next;
        while (head != nextHead)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        preTail->next = reverseKGroup(nextHead, k);
        return pre;
    }
};