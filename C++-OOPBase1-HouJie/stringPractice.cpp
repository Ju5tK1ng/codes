#include <iostream>
#include <cstring>
using namespace std;

#ifndef __STRING__
#define __STRING__

class String
{
public:
    String (const char* c_str = 0)
    {
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
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
    }

    ~String()
    {
        delete[] m_data;
    }

    String& operator = (const String& str)
    {
        if (this == &str)
        {
            return *this;
        }
        delete[] m_data;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
        return *this;
    }

    char* c_str() const
    {
        return m_data;
    }

private:
    char* m_data;

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
    String s3("s3");
    String s4(s2);
    s2 = s3;

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
}
