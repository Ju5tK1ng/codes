#include <bits/stdc++.h>
using namespace std;
class MyQueue {
private:
    stack<int> in, out;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek();
        out.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }
};
