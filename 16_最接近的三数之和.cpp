#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    if(nums < 3)
        return 0;
    
    // 将nums排序
    sort(nums.begin(), nums.end());

     // closestSum初始化为最大值
    int closestSum = INT_MAX;
    int n = nums.size();

    for(int i = 0; i < n; i++)
    {
        // 初始化左右指针
        int left = i + 1;
        int right = n - 1 ;

        while(left < right)
        {
            // 计算三数之和
            int sum = nums[i] + nums[left] + nums[right];
           
            if(sum == target)      // 如果三数之和等于target，则直接返回
            {
                return target;
            }
            else if(sum < target)  // 如果三数之和小于target，则左指针右移
            {
                left++;
            }
            else                   // 如果三数之和大于target，则右指针左移
            {
                right--;
            }

            if(abs(sum -target) < abd(closestSum - target) )  // 更新closestSum
            {
                closestSum = sum;
            }
        }  
    }

    return closestSum;
}