#include<bits/stdc++.h>
using namespace std;
class SeatManager {
    set<int> s;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++)
        {
            s.insert(i);
        }
    }
    
    int reserve() {
        int ans = *s.begin();
        s.erase(s.begin());
        return ans;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};