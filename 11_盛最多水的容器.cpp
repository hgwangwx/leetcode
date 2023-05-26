#include <vector>
#include<cmatch>

using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;                          // 左边界
    int right = height.size()-1;           // 右边界
    int ans = 0;                           // 最大面积

    while(left < right)                    // 当左右指针不重合时
    {
        int area = (right  -left ) * min(height[right], height[left]);
        ans = max(ans, area);

        if(height[left] <= height[right])   // 如果左边界高度小于右边界
        {
            left++;                         // 左指针右移
        }
        else {                              // 如果右边界高度小于左边界
            right--;                        // 右指针左移
        }
    }

    return ans;
}