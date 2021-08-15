#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 插入
    void Insertion_Sort(vector<int>& nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            int t = nums[i];
            int j = i - 1;
            for (; j >= 0 && nums[j] > t; j--)
            {
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = t;
        }
    }
    
    // 冒泡
    void Bubble_Sort(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            bool flag = false;
            for (int j = nums.size() - 1; j > i; j--)
            {
                if (nums[j - 1] > nums[j])
                {
                    swap(nums[j - 1], nums[j]);
                    flag = true;
                }
            }
            if (!flag)
            {
                return;
            }
        }
    }
    
    // 选择
    void Selection_Sort(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[minIndex] > nums[j])
                {
                    minIndex = j;
                }
            }
            swap(nums[i], nums[minIndex]);
        }
    }
    
    // 希尔
    void Shell_Sort(vector<int>& nums)
    {
        for (int gap = nums.size() / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < nums.size(); i++)
            {
                int t = nums[i];
                int j = i - gap;
                for (; j >= 0 && nums[j] > t; j -= gap)
                {
                    nums[j + gap] = nums[j];
                }
                nums[j + gap] = t;
            }
        }
    }
    // 堆
    void Adjust(vector<int>& nums, int n, int i)
    {
        int maxn = i, l = i * 2 + 1, r = i * 2 + 2;
        if (l < n && nums[maxn] < nums[l])
        {
            maxn = l;
        }
        if (r < n && nums[maxn] < nums[r])
        {
            maxn = r;
        }
        if (maxn != i)
        {
            swap(nums[i], nums[maxn]);
            Adjust(nums, n, maxn);
        }
    }

    void Heap_Sort(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            Adjust(nums, n, i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            swap(nums[0], nums[i]);
            Adjust(nums, i, 0);
        }
    }

    // 归并
    void Merge_Sort(vector<int>& nums, vector<int>& T, int l, int r)
    {
        if (r - l <= 1)
        {
            return;
        }
        int m = l + (r - l) / 2;
        Merge_Sort(nums, T, l, m);
        Merge_Sort(nums, T, m, r);
        int p = l, q = m, i = l;
        while (p < m || q < r)
        {
            if (q >= r || p < m && nums[p] <= nums[q])
            {
                T[i++] = nums[p++];
            }
            else
            {
                T[i++] = nums[q++];
            }
        }
        for (i = l; i < r; i++)
        {
            nums[i] = T[i];
        }
    }

    // 快速
    void Quick_Sort(vector<int>& nums, int l, int r)
    {
        if (r - l <= 1)
        {
            return;
        }
        swap(nums[l], nums[l + (r - l) / 2]);
        int i = l, j = r - 1, pivot = nums[l];
        while (i < j)
        {
            while (i < j && pivot <= nums[j])
            {
                j--;
            }
            nums[i] = nums[j];
            while (i < j && pivot >= nums[i])
            {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        Quick_Sort(nums, l, i);
        Quick_Sort(nums, i + 1, r);
    }

    // 计数
    void Count_Sort(vector<int>& nums)
    {
        int minn = *min_element(nums.begin(), nums.end());
        int maxn = *max_element(nums.begin(), nums.end());
        vector<int> cnt(maxn - minn + 1, 0);
        for (int& num : nums)
        {
            cnt[num - minn]++;
        }
        int cur = 0;
        for (int i = 0; i < cnt.size(); i++)
        {
            while(cnt[i] > 0)
            {
                nums[cur++] = i + minn;
                cnt[i]--;
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        // Insertion_Sort(nums);
        // Bubble_Sort(nums);
        // Selection_Sort(nums);
        // Shell_Sort(nums);
        // vector<int> T(nums);
        // Merge_Sort(nums, T, 0, nums.size());
        // Quick_Sort(nums, 0, nums.size());
        // Heap_Sort(nums);
        // Count_Sort(nums);
        sort(nums.begin(), nums.end());
        return nums;
    }
};