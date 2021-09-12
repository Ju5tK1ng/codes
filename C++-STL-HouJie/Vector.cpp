#include <bits/stdc++.h>
using namespace std;

#ifndef __VECTOR__
#define __VECTOR__

template<typename T>
class Vector
{
public:
    typedef T* iterator;
protected:
    iterator start;
    iterator finish;
    iterator end_of_storage;
public:
    Vector(const size_t& n = 0)
    {
        start = new T[n];
        finish = start;
        end_of_storage = start + n;
    }

    ~Vector()
    {
        delete[] start;
    }

    Vector(const Vector& v)
    {
        start = new T[v.size()];
        finish = uninitialized_copy(v.start, v.finish, start);
        end_of_storage = start + v.size();
    }

    Vector& operator = (const Vector& v)
    {
        if (this == &v)
        {
            return *this;
        }
        clear();
        start = new T[v.size()];
        finish = uninitialized_copy(v.start, v.finish, start);
        end_of_storage = start + v.size();
        return *this;
    }

    iterator begin() const
    {
        return start;
    }

    iterator end() const
    {
        return finish;
    }

    size_t size() const
    {
        return size_t(end() - begin());
    }

    size_t capacity() const
    {
        return size_t(end_of_storage - begin());
    }

    bool empty() const
    {
        return begin() == end();
    }

    T& operator [] (size_t n) const
    {
        return *(begin() + n);
    }

    T& front() const
    {
        return *begin();
    }

    T& back() const
    {
        return *(end() - 1);
    }

    void push_back(const T& x)
    {
        if (finish != end_of_storage)
        {
            *finish = x;
            finish++;
        }
        else
        {
            insert(end(), x);
        }
    }

    void pop_back()
    {
        if (finish != start)
        {
            finish--;
        }
    }

    iterator insert(iterator position, const T& x)
    {
        if (finish != end_of_storage)
        {
            for (iterator ite = finish; ite != position; ite--)
            {
                *ite = *(ite - 1);
            }
            *position = x;
            finish++;
        }
        else
        {
            const size_t old_size = size();
            const size_t len = old_size != 0 ? 2 * old_size : 1;
            iterator new_start = new T[len];
            iterator new_finish = uninitialized_copy(start, position, new_start);
            *new_finish = x;
            new_finish++;
            new_finish = uninitialized_copy(position, finish, new_finish);
            position = position - start + new_start;
            delete[] start;
            start = new_start;
            finish = new_finish;
            end_of_storage = start + len;
        }
        return position;
    }

    iterator erase(iterator position)
    {
        for (iterator ite = position; ite != finish - 1; ite++)
        {
            *ite = *(ite + 1);
        }
        if (finish != start)
        {
            finish--;
        }
        return position;
    }

    void resize(const size_t& new_size)
    {
        if (new_size > capacity())
        {
            iterator new_start = new T[new_size];
            iterator new_finish = uninitialized_copy(start, finish, new_start);
            start = new_start;
            finish = new_finish;
            end_of_storage = finish;
        }
        else
        {
            finish = start + new_size;
        }
    }

    void clear()
    {
        delete[] start;
        finish = start;
    }

};

#endif


int main()
{
    Vector<int> V;
    cout << sizeof(V) << endl;
    cout << 0 << ": " << V.size() << " " << V.capacity() << endl;
    cout << V.empty() << endl;
    for (int i = 0; i < 5; i++)
    {
        V.push_back(i);
        cout << V[i] << ": " << V.size() << " " << V.capacity() << endl;
    }
    cout << V.empty() << endl;
    cout << V.front() << " " << V.back() << " " << *V.begin() << " " << *(V.end() - 1) << endl;
    cout << "---------------" << endl;
    Vector<int> V2(V);
    for (int i = 5; i < 11; i++)
    {
        cout << *V2.insert(V2.begin() + 2, i) << ": " << V2.size() << " " << V2.capacity() << endl;
    }
    sort(V2.begin(), V2.end());
    cout << "---------------" << endl;
    Vector<int> V3;
    V3 = V2;
    cout << V3.back() << ": " << V3.size() << " " << V3.capacity() << endl;
    V3.pop_back();
    cout << V3.back() << ": " << V3.size() << " " << V3.capacity() << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << *V3.erase(V3.begin() + 1) << ": " << V3.size() << " " << V3.capacity() << endl;
    }
    V3.resize(2);
    cout << "resize: " << V3.size() << " " << V3.capacity() << endl;
    V3.clear();
    cout << "clear: " << V3.size() << " " << V3.capacity() << endl;

    cout << "-----------------------------------" << endl;

    vector<int> v;
    cout << sizeof(v) << endl;
    cout << 0 << ": " << v.size() << " " << v.capacity() << endl;
    cout << v.empty() << endl;
    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
        cout << v[i] << ": " << v.size() << " " << v.capacity() << endl;
    }
    cout << v.empty() << endl;
    cout << v.front() << " " << v.back() << " " << *v.begin() << " " << *(v.end() - 1) << endl;
    cout << "---------------" << endl;
    vector<int> v2(v);
    for (int i = 5; i < 11; i++)
    {
        cout << *v2.insert(v2.begin() + 2, i) << ": " << v2.size() << " " << v2.capacity() << endl;
    }
    sort(v2.begin(), v2.end());
    cout << "---------------" << endl;
    vector<int> v3;
    v3 = v2;
    cout << v3.back() << ": " << v3.size() << " " << v3.capacity() << endl;
    v3.pop_back();
    cout << v3.back() << ": " << v3.size() << " " << v3.capacity() << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << *v3.erase(v3.begin() + 1) << ": " << v3.size() << " " << v3.capacity() << endl;
    }
    v3.resize(2);
    cout << "resize: " << v3.size() << " " << v3.capacity() << endl;
    v3.clear();
    cout << "clear: " << v3.size() << " " << v3.capacity() << endl;
    return 0;
}
