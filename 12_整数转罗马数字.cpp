#include <string>

using namespace std;

const pair<int , string> valueSymbols[] = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"},
};

string intToRoman(int num) {
    string roman;
    
    for(const auto &[value, symbol] :valueSymbols )
    {
        while(num >= value)     // 如果当前值比 num 大，跳过
        {
            num = num -value;
            roman += symbol;    // 添加对应的符号
        }

        if(num ==0) 
            break;
    }

    return roman;
}