#include <string>
#include <limits.h>

using namespace std;

int isdigit(char c) {
  return (c >= '0' && c <= '9');
}

int strToInt(string &str)
{
    //空判断
    if(str.empty()) return 0;

    //去除空格
    int index = 0;
    int n = str.size();
    while(index < n && str[index] == ' ')
    {
        ++index;
    }


    int sign = 1;
    int signNum = 0;
    //处理符号
    while(index < n && str[index] == '+' || str[index] == '-')
    {
        sign = (str[index] == '+')?1:-1;
        signNum++;
        ++index;
    }

    if(signNum >1)
    {
        return 0;
    }

    int res = 0;
    //数字转换
    while(index < n && isdigit(str[index])){
        int  digit = str[index] - '0';
        //判断是否溢出
        if(res > (INT_MAX - digit) /10){
            return sign == 1?INT_MAX:INT_MIN;
        }
        res = res*10  + digit;
        ++index;
    }

    return res * sign;
}