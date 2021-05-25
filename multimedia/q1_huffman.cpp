#include<bits/stdc++.h>
using namespace std;
struct Node
{
    float probability;
    unordered_set<string> s;
    Node(float _probability = 0, string name = "")
    {
        probability = _probability;
        s.insert(name);
    }
    friend bool operator < (const Node& x, const Node& y)
    {
        return x.probability > y.probability;
    }
    Node& operator += (const Node& y)
    {
        probability += y.probability;
        s.insert(y.s.begin(), y.s.end());
        return *this;
    }
};
int main()
{
    unordered_map<string, float> input = 
    {
        {"green", 0.405},
        {"cyan", 0.251},
        {"red", 0.086},
        {"purple", 0.086},
        {"yellow", 0.086},
        {"orange", 0.086},
    };
    unordered_map<string, string> output;
    priority_queue<Node, vector<Node>> pq;
    for (auto& p : input)
    {
        Node node(p.second, p.first);
        pq.push(node);
    }
    while (pq.size() > 1)
    {
        Node node0 = pq.top();
        pq.pop();
        Node node1 = pq.top();
        pq.pop();
        for (auto& str : node0.s)
        {
            output[str] = "0" + output[str];
        }
        for (auto& str : node1.s)
        {
            output[str] = "1" + output[str];
        }
        node0 += node1;
        pq.push(node0);
    }
    for (auto& str : pq.top().s)
    {
        cout << str << ": " << output[str] << endl;
    }
    return 0;
}