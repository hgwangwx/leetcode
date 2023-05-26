#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& nums)
{
    int n = nums.size();

    //从0~n-2循环遍历整个数组
    for(int i = 0; i < n-1; i++)
    {
        int midIndex = i;

        // 从i+1~n-1中寻找最小值
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[midIndex]) {
                midIndex = j;
            }
        }

        // 将找到的最小值和当前位置i上的值交换
        swap(nums[i], nums[midIndex]);
    }

}