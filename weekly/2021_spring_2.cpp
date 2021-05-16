#include<bits/stdc++.h>
using namespace std;
int orchestraLayout(int num, int xPos, int yPos) {
    long long ans = 0;
    long long n = num;
    long long bian = min(min(xPos, num - 1 - xPos), min(yPos, num - 1 - yPos));
    long long size = n - bian * 2;
    ans = (n * n - size * size) % 9;
    xPos -= bian;
    yPos -= bian;
    ans++;
    if (xPos == 0)
    {
        ans = (ans + yPos) % 9;
    }
    else if (yPos == size - 1)
    {
        ans = (ans + size - 1 + xPos) % 9;
    }
    else if (xPos == size - 1)
    {
        ans = (ans + (size - 1) * 2 + size - 1 - yPos) % 9;
    }
    else
    {
        ans = (ans + (size - 1) * 3 + size - 1 - xPos) % 9;
    }
    return ans == 0 ? 9 : ans;
}