#include <vector>
#include <unordered_map>

using namesapce std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> hash;
    for(int i = 0; i < nums.size(); i++)
    {
        //是否存在该目标值
        auto it = hash.find(target - nums[i])
        if(it != hash.end())
        {
            //找到该目标值，则返回
            return {i, it->second};
        }

        //存储value+id
        hash[nums[i]] = i;
    }

    return {};
}