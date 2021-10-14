#include <iostream>
#include <cstring>
using namespace std;

#ifndef __STRING__
#define __STRING__

class String
{
private:
    char* m_data;

public:
    String (const char* c_str = 0)
    {
        if (c_str != 0)
        {
            cout << c_str << endl;
        }
        if (c_str)
        {
            m_data = new char[strlen(c_str) + 1];
            strcpy(m_data, c_str);
        }
        else
        {
            m_data = new char[1];
            *m_data = '\0';
        }
    }

    String (const String& str)
    {
        cout << "copy construct: " << str.m_data << endl;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
    }

    String (String&& str) : m_data(str.m_data)
    {
        cout << "move construct: " << str.m_data << endl;
        str.m_data = nullptr;
    }

    ~String()
    {
        delete[] m_data;
    }

    String& operator = (const String& str)
    {
        cout << "copy assignment: " << str.m_data << endl;
        if (this == &str)
        {
            return *this;
        }
        delete[] m_data;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
        return *this;
    }

    String& operator = (String&& str)
    {
        cout << "move assignment: " << str.m_data << endl;
        if (this == &str)
        {
            return *this;
        }
        delete[] m_data;
        m_data = str.m_data;
        str.m_data = nullptr;
        return *this;
    }

    char* c_str() const
    {
        return m_data;
    }
};

ostream& operator << (ostream& os, const String& str)
{
    os << str.c_str();
    return os;
}

#endif

int main()
{
    String s1;
    String s2("s2");

    String s3(s2);
    String s4(move(String("s4"))); // 不加move，只会执行一次构造函数，不会执行move构造函数

    String s5;
    String s6;
    s5 = s2;
    s6 = String("s6");

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
}
