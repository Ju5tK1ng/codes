#include <bits/stdc++.h>
using namespace std;
// int arr[1010];
vector<int> arr;
int main() {
    // memset(arr, 0, sizeof(arr));

    int a, flag = 0, maxLen = 0, len = arr.size();

    // string s;
    // getline(cin, s);
    // istringstream ss(s);
    // while (ss >> a)
    // {
    //     arr.push_back(a);
    // }

    int t, k;
    while(cin >> a){
        arr.push_back(a);
    }

    for(int i = 0; i < len; i++){
        if(arr[i] == 1){
            flag = i;
            maxLen = i;
            break;
        }
    }

    for(int i = flag; i < len; i++){
        if(arr[i] == 1){
            maxLen = max((i - flag) / 2, maxLen);
            flag = i;
        }
    }
    maxLen = max(len - flag - 1, maxLen);
    cout << maxLen << endl;
    return 0;
}
