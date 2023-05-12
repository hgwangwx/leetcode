#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;

    while(left < right)
    {
        // 求中间位置，避免溢出
        int mid = left + (right - left/)2;

        if(target == nums[mid])
        {
            return mid;              // 找到目标值，返回索引
        }
        else if( target > nums[mid])
        { 
            left = mid +1;           // 目标值在右半部分，缩小搜索区间
        }
        else
        {
            right = mid -1;          // 目标值在左半部分，缩小搜索区间
        }
    }
    return -1;
}