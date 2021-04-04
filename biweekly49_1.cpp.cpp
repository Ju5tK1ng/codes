#include<bits/stdc++.h>
using namespace std;
bool squareIsWhite(string coordinates) {
    if(((coordinates[0] - 'a') + (coordinates[0] - '0')) / 2)
    {
        return true;
    }
    return false;
}