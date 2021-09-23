#include <bits/stdc++.h>
using namespace std;
// 同lc232
class CQueue {
private:
    stack<int> in, out;
public:
    CQueue() {

    }

    void appendTail(int value) {
        in.push(value);
    }

    int deleteHead() {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        if (out.empty())
        {
            return -1;
        }
        int x = out.top();
        out.pop();
        return x;
    }
};
