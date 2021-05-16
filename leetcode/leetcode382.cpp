#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode* node = head;
        int ans = node->val;
        int cnt = 1;
        while (node->next)
        {
            node = node->next;
            cnt++;
            if (rand() % cnt == 0)
            {
                ans = node->val;
            }
        }
        return ans;
    }
};
int main()
{
    srand(time(NULL));
    int n;
    cin >> n;
    ListNode* head = new ListNode();
    cin >> head->val;
    ListNode* thead = head;
    for (int i = 1; i < n; i++)
    {
        thead->next = new ListNode();
        thead = thead->next;
        cin >> thead->val;
    }
    Solution* obj = new Solution(head);
    for (int i = 0; i < 10; i++)
    {
        cout << obj->getRandom();
        if (i != 9)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
    return 0;
}