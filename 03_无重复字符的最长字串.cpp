#include <unordered_map>
#include <string>

using namespace std;

int lengOfLongestSubstring(std::string s)
{
    // 哈希集合，记录每个字符是否出现过
    unordered_set<char> occ;
    int n = s.size();

    // 右指针，初始化为-1，相当于我们再字符串的左边界的左侧，还没开始移动
    int rk = -1;
    int ans = 0;

    // 枚举左指针的位置，初始值隐性地标识为-1
    for(int i = 0; i < n; i++)
    {
        if(i !=0 )
        {
            //移除滑动窗口
            occ.erase(s[i-1]);
        }

        while(rk+1 < n && !occ.count(s[rk+1])) {
            occ.insert(s[rk+1]);
            rk++;
        }

        
        ans = max(ans, rk-i+1);
    }
    return ans;
}
