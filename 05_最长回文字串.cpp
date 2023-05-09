#include<string>

using namespace std;

pair<int , int > expandAroundCenter(const string &s, const int left, const int right)
{
    //进行中心扩张
    while(left >= 0 && right <= s.size() && s[left] == s[right])
    {
        left--;
        right++;
    }

    return pair[left+1, right-1];
}

string longestPalindrome(string& s)
{
    int start = 0;
    int end = 0;

    for(int i = 0; i < s.size(); i++)
    {
        //中心扩张法
        auto[left1, right1] = expandAroundCenter(s, i , i);
        auto[left2, right2] = expandAroundCenter(s, i , i+1);

        if(right1 - left1 > end -start)
        {
            start = left1;
            end = right1;
        }

        if(right2 - left2 > end -start)
        {
            start = left2;
            end = right2;
        }
    }

    return s.substr(start, end-start+1);
}