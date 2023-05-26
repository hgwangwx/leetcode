#include <iostream>
#include <vector>

using namespace std;

void insertSort(std::vector<int>& arr) {
    int n = arr.size();

    // 从第二个元素开始遍历，将当前元素插入到已排序的子数组中
    for(int i = 1; i < n; ++i)
    {
        int key = arr[i];   // 当前要插入的元素
        int j = i -1;       // 已排序子数组的最后一个元素的索引

        // 将比当前元素大的元素向右移动
        while(j >=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];  // 向后移动元素
            --j;
        }

        arr[j+1] = key;  //插入key找到合适的位置
    }
}