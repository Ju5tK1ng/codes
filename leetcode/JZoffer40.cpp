#include<bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<int, vector<int>> pq;
        for (int& i : arr)
        {
            pq.push(i);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

// 2.0
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r, int k)
    {
        if (l >= r)
        {
            return;
        }
        swap(nums[l], nums[l + (r - l) / 2]);
        int i = l, j = r, pivot = nums[l];
        while (i < j)
        {
            while (i < j && pivot <= nums[j])
            {
                j--;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] <= pivot)
            {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        if (i == k)
        {
            return;
        }
        else if (i > k)
        {
            quick_sort(nums, l, i - 1, k);
        }
        else
        {
            quick_sort(nums, i + 1, r, k);
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick_sort(arr, 0, arr.size() - 1, k);
        arr.resize(k);
        return arr;
    }
};
