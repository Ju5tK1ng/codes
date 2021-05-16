#include<bits/stdc++.h>
using namespace std;
int rand7()
{
    return rand() % 7 + 1;
}
class Solution {
public:
    int rand10() {
        int a = (rand7() - 1) * 7 + rand7() - 1;
        while (a >= 40)
        {
            a = (rand7() - 1) * 7 + rand7() - 1;
        }
        return a % 10 + 1;
    }
};