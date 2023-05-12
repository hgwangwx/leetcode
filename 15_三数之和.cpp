#include <vector>
#include <algorithm>

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>  result;

    // 如果元素个数小于3个，直接返回
    if (nums.size() < 3) {
        return result;
    }

    // 先对数组排序，方便后续的去重和双指针查找
    sort(nums.begin(), nums.end());

    // 固定第一个数，查找后面两个数之和为其相反数的情况
    for(int i = 0; i < nums.size()-2; i++)
    {
        // 如果当前数字与前一个数字相同，跳过避免重复
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }

        // 定义双指针 left 和 right，分别指向当前数之后的两端
        int left = i + 1;
        int right = nums.size() - 1;

        // 双指针查找
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});                
                left++;
                right--;
                
                // 如果左侧数字与前一个数字相同，跳过避免重复
                while(left < right && nums[left] == nums[left-1])
                {
                    left++;
                }

                // 如果右侧数字与后一个数字相同，跳过避免重复
                while(left < right && nums[right] == nums[right+1])
                {
                    right--;
                }

            }
            else if(sum < 0)
            {
                // 如果和小于0，说明左侧数字过小，需要增加左侧数字
                left++;
            }
            else 
            {
                // 如果和大于0，说明右侧数字过大，需要减小右侧数字
                right --;
            }
        }
    }

    return result;
}