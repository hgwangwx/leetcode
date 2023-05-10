#include<string>
#include <vector>

using namespace std;

string convert(string &s, int numRows)
{
    if(numRows < 2) return s;                  // 给定行为1,结果与原字串一致

    vector<string> rows(numRows);              // 创建res保持每行结果
    int idxRows = 0;                           // 行下标索引
    int flag = -1;                             // 行转向标志

    for(char &ch: s) {                         // 遍历s
        rows[idxRows] += ch;
        if(idxRows == 0 || idxRows == numRows -1)  { // 行收尾变向
            //转向，上->下 || 下->上
            flag = -flag;
        }
        idxRows += flag;
    }

    string res;
    for(auto row: rows)                        //将每行接起来就是结果
    {
        res += row;
    }
    return res;
 }