#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* ans = new ListNode();
    ListNode *tans = ans;
    while (head && head->next)
    {
        tans->next = head->next;
        tans->next->next = head;
        head->next = head->next->next;
        tans = head;
        head = head->next;
    }
    tans->next = head;
    return ans->next;
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
    thead = swapPairs(head);
    while (thead)
    {
        cout << thead->val << " ";
        thead = thead->next;
    }
    cout << endl;
    return 0;
}