#include<bits/stdc++.h>
using namespace std;
// 1.1
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int cnt = m + n - 1;
    m--;
    n--;
    while (m >= 0 || n >= 0)
    {
        if (n < 0 || (m >= 0 && nums1[m] > nums2[n]))
        {
            nums1[cnt--] = nums1[m--];
        }
        else
        {
            nums1[cnt--] = nums2[n--];
        }
    }
}
int main()
{
    vector<int> nums1, nums2;
    int m, n, t;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        nums1.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        nums2.push_back(t);
    }
    nums1.resize(m + n);
    merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i];
        if (i != m + n - 1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
    return 0;
}