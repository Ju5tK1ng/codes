#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1.0
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        while (head)
        {
            ans.push_back(head->val);
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 2.0
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        int n = 0;
        ListNode* thead = head;
        while (thead)
        {
            n++;
            thead = thead->next;
        }
        vector<int> ans(n);
        while (head)
        {
            n--;
            ans[n] = head->val;
            head = head->next;
        }
        return ans;
    }
};
