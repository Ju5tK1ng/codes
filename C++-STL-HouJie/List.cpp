#include <bits/stdc++.h>
using namespace std;

#ifndef __LIST__
#define __LIST__

template<typename T>
class List_Node
{
public:
    List_Node<T>* next;
    List_Node<T>* prev;
    T data;

    List_Node() {}
    List_Node(T _data) : data(_data) {}
};


template<typename T>
class List_Iterator
{
public:
    typedef List_Iterator<T> self;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef ptrdiff_t difference_type;

    List_Node<T>* node;

    List_Iterator(List_Node<T>* _node) : node(_node) {}

    T& operator * () const
    {
        return node->data;
    }

    T* operator -> () const
    {
        return &(operator * ());
    }

    self& operator ++ ()
    {
        node = node->next;
        return *this;
    }

    self operator ++ (int)
    {
        self tmp = *this;
        node = node->next;
        return tmp;
    }

    self& operator -- ()
    {
        node = node->prev;
        return *this;
    }

    self operator -- (int)
    {
        self tmp = *this;
        node = node->prev;
        return tmp;
    }

    bool operator == (const self& r) const
    {
        return node == r.node;
    }

    bool operator != (const self& r) const
    {
        return node != r.node;
    }
};


template<typename T>
class List
{
private:
    size_t _size;
    List_Node<T>* node;
public:
    typedef List_Iterator<T> iterator;

    List()
    {
        _size = 0;
        node = new List_Node<T>();
        node->next = node;
        node->prev = node;
    }

    ~List()
    {
        clear();
        delete node;
    }

    List(const List& l)
    {
        cout << "ctr" << endl;
        _size = 0;
        node = new List_Node<T>();
        node->next = node;
        node->prev = node;
        for (auto ite = l.begin(); ite != l.end(); ite++)
        {
            push_back(*ite);
        }
    }

    List& operator = (const List& l)
    {
        if (this == &l)
        {
            return *this;
        }
        clear();
        for (auto ite = l.begin(); ite != l.end(); ite++)
        {
            push_back(*ite);
        }
        return *this;
    }

    bool operator == (const List& l) const
    {
        auto i1 = begin();
        auto end1 = end();
        auto i2 = l.begin();
        auto end2 = l.end();
        while (i1 != end1 && i2 != end2 && *i1 == *i2)
        {
            ++i1;
            ++i2;
        }
        return i1 == end1 && i2 == end2;
    }

    size_t size() const
    {
        return _size;
    }

    bool empty() const
    {
        return node->next == node;
    }

    iterator begin() const
    {
        return iterator(node->next);
    }

    iterator end() const
    {
        return iterator(node);
    }

    iterator insert(iterator ite, T value)
    {
        List_Node<T>* prev = ite.node->prev;
        ite.node->prev = new List_Node<T>(value);
        ite.node->prev->next = ite.node;
        ite.node->prev->prev = prev;
        prev->next = ite.node->prev;
        _size++;
        return iterator(prev->next);
    }

    void push_back(T data)
    {
        insert(end(), data);
    }

    void push_front(T data)
    {
        insert(begin(), data);
    }

    iterator erase(iterator ite)
    {
        List_Node<T>* next = ite.node->next;
        ite.node->prev->next = next;
        next->prev = ite.node->prev;
        delete ite.node;
        _size--;
        return next;
    }

    void pop_back()
    {
        erase(iterator(node->prev));
    }

    void pop_front()
    {
        erase(begin());
    }

    void clear()
    {
        auto ite = begin();
        while (ite != end())
        {
            auto tmp = ite;
            ite++;
            delete tmp.node;
        }
        _size = 0;
        node->next = node;
        node->prev = node;
    }
};

#endif


int main()
{
    cout << sizeof(List_Node<int>) << " " << sizeof(List_Iterator<int>) << " " << sizeof(List<int>) << endl;
    List<int> L1;
    for (int i = 0; i < 3; i++)
    {
        L1.push_back(i);
    }
    cout << L1.size() << endl;
    for (auto ite = L1.begin(); ite != L1.end(); ite++)
    {
        cout << *ite << endl;
    }
    cout << "-----------" << endl;
    List<int> L2(L1);
    L2.push_front(-1);
    L2.pop_back();
    cout << *(--L2.end()) << endl;
    for (auto ite = L2.begin(); ite != L2.end(); ite++)
    {
        cout << *ite << endl;
    }
    cout << "-----------" << endl;
    List<int> L3;
    L3 = L2;
    cout << (L3 == L2) << endl;
    cout << L3.empty() << endl;
    L3.clear();
    cout << L3.empty() << endl;
    cout << sizeof(List<int>) << endl;

    cout << "--------------------------" << endl;

    list<int> l1;
    for (int i = 0; i < 3; i++)
    {
        l1.push_back(i);
    }
    cout << l1.size() << endl;
    for (auto ite = l1.begin(); ite != l1.end(); ite++)
    {
        cout << *ite << endl;
    }
    cout << "-----------" << endl;
    list<int> l2(l1);
    l2.push_front(-1);
    l2.pop_back();
    cout << *(--l2.end()) << endl;
    for (auto ite = l2.begin(); ite != l2.end(); ite++)
    {
        cout << *ite << endl;
    }
    cout << "-----------" << endl;
    list<int> l3;
    l3 = l2;
    cout << (l3 == l2) << endl;
    cout << l3.empty() << endl;
    l3.clear();
    cout << l3.empty() << endl;
    cout << sizeof(list<int>) << endl;
    return 0;
}
