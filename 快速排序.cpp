#include <iostream>
#include <vector>

using namespace std;

// 快速排序函数
void quickSort(vector<int>& nums, int left, int right) {
    // 如果待排序数组为空或只有一个元素，不需要进行排序
    if(left >= right ) return;

    // 选择数组最左侧的元素作为基准元素
    int pivot = left;

    // 定义两个指针，分别从数组的左右两端开始向中间扫描
    int i = left+1;
    int j = right;

    // 开始扫描
    while(i <= j)
    {
        // 找到第一个大于等于基准元素的数
        while(i <= j && nums[i] < nums[pivot]){
            i++;
        } 

        // 找到第一个小于等于基准元素的数
        while(i <= j && nums[j] > nums[pivot]) {
            j--;
        }

        // 如果 i <= j，交换这两个数的位置
        if( i <= j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
        
    // 把基准元素交换到中间位置
    swap(nums[left], nums[j]);

    // 递归排序左半部分和右半部分
    quickSort(nums, left, j-1);
    quickSort(nums, j+1, right);
}