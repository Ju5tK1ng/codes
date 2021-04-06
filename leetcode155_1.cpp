#include<bits/stdc++.h>
using namespace std;
class MinStack {
    stack<int> s, s_min;
public:
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        if (s_min.empty() || val <= s_min.top())
        {
            s_min.push(val);
        }
    }
    
    void pop() {
        if (!s_min.empty() && s.top() == s_min.top())
        {
            s_min.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s_min.top();
    }
};