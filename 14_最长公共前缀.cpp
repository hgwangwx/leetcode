#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    // 如果输入为空，返回空字符串
    if(!strs.size())
        return "";

    // 记录最长公共前缀
    string prefix = strs[0];
    // 从第二个字符串开始遍历，依次更新最长公共前缀
    for(int i = 1; i < strs.size(); i++)
    {
        // 如果当前字符串不以最长公共前缀开头，不断缩短最长公共前缀，直到符合条件
        while(strs[i].find(prefix) != 0)
        {
            // 如果最长公共前缀为空，说明不存在公共前缀，直接返回空字符串
            prefix = prefix.substr(0, prefix.size() - 1);

            if(prefix.empty())
                return "";
        }
    }
    return prefix;
}