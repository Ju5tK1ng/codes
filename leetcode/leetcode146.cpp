#include <bits/stdc++.h>
using namespace std;
class LRUCache {
    int size;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        auto it = hash.find(key);
        if (it == hash.end())
        {
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return cache.begin()->second;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if (it != hash.end())
        {
            cache.splice(cache.begin(), cache, it->second);
            cache.begin()->second = value;
            return;
        }
        cache.push_front(make_pair(key, value));
        hash[key] = cache.begin();
        if (cache.size() > size)
        {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
    }
};

// 1.1
struct Node
{
    int key, val;
    Node *pre, *next;
    Node(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr) {}
};
class LRUCache {
    int size = 0, capacity;
    Node *head, *tail;
    unordered_map<int, Node*> hash;
    void Splice(Node* InsertNode)
    {
        InsertNode->pre->next = InsertNode->next;
        InsertNode->next->pre = InsertNode->pre;
        InsertNode->pre = head;
        InsertNode->next = head->next;
        head->next = InsertNode;
        InsertNode->next->pre = InsertNode;
    }

    void Add(Node* Node)
    {
        Node->pre = head;
        Node->next = head->next;
        head->next = Node;
        Node->next->pre = Node;
        size++;
    }

    void RemoveBack()
    {
        tail->pre = tail->pre->pre;
        delete(tail->pre->next);
        tail->pre->next = tail;
        size--;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        auto it = hash.find(key);
        if (it == hash.end())
        {
            return -1;
        }
        Splice(it->second);
        return head->next->val;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if (it != hash.end())
        {
            Splice(it->second);
            head->next->val = value;
            return;
        }
        Node* newHead = new Node(key, value);
        Add(newHead);
        hash[key] = newHead;
        if (size > capacity)
        {
            hash.erase(tail->pre->key);
            RemoveBack();
        }
    }
};
