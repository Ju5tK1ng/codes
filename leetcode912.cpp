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

    // 堆

    // 归并

    // 快速

    // 桶
    vector<int> sortArray(vector<int>& nums) {
        // Insertion_Sort(nums);
        // Bubble_Sort(nums);
        Selection_Sort(nums);
        return nums;
    }
};