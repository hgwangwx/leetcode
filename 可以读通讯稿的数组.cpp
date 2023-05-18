#include<iostream>
#include<vector>
#include<>

using namespace std;

//A + B镜像 = A镜像 + B 为 B镜像 - B = A镜像 - A。 那么数对就是，差值相同，就可以组成数对
int numberOfPairs(vector<int>& nums)
{
    int n = nums.size();

    vecotr<long long> dis(n); // 用于存储每个元素的差值
    map<long long, int> mp;   // 用于统计每个差值的出现次数

    int mod = 1e9+7; // 取模常量

    // 计算每个元素的差值并统计出现次数
    for (int i = 0; i < nums.size(); i++) {
        long long tmp = 0, x = nums[i];
        while(x){
            tmp = tmp*10+ x%10;
            x/=10;
        }
        dis[i] = tmp - nums[i];
        mp[dis[i]] +=1;
    }

    int ans = 0;
    // 遍历差值数组，计算满足条件的数对数量
    for(int i=0;i<n;i++) {
        if(mp[dis[i]] >= 2){        
            ans = (mp[dis[i]] -1 + ans) % mod; // 更新答案，注意取模
            mp[dis[i]] -= 1;                   // 将该差值的出现次数减1，避免重复计数
        }
    }
    return ans;
}