#include<bits/stdc++.h>
using namespace std;
class MKAverage {
    int m, k;
    long long sum = 0;
    multiset<int> lower, middle, upper;
    queue<int> q;
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }
    
    void addElement(int num) {
        q.push(num);
        if (q.size() > m)
        {
            int t = q.front();
            q.pop();
            if (num <= *lower.rbegin())
            {
                lower.insert(num);
                if (lower.size() > k)
                {
                    middle.insert(*lower.rbegin());
                    sum += *lower.rbegin();
                    lower.erase(--lower.end());
                }
            }
            else if (num >= *upper.begin())
            {
                upper.insert(num);
                if (upper.size() > k)
                {
                    middle.insert(*upper.begin());
                    sum += *upper.begin();
                    upper.erase(upper.begin());
                }
            }
            else
            {
                middle.insert(num);
                sum += num;
            }
            if (t <= *lower.rbegin())
            {
                lower.erase(lower.find(t));
            }
            else if (t >= *upper.begin())
            {
                upper.erase(upper.find(t));
            }
            else
            {
                sum -= t;
                middle.erase(middle.find(t));
            }
        }
        else
        {
            middle.insert(num);
            sum += num;
        }
        if (q.size() == m)
        {
            while (lower.size() < k)
            {
                lower.insert(*middle.begin());
                sum -= *middle.begin();
                middle.erase(middle.begin());
            }
            while (upper.size() < k)
            {
                upper.insert(*middle.rbegin());
                sum -= *middle.rbegin();
                middle.erase(--middle.end());
            }
        }
    }
    
    int calculateMKAverage() {
        if (q.size() < m)
        {
            return -1;
        }
        return sum / (m - 2 * k);
    }
};