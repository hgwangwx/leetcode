#include <vector>
#include <queue>

using namespace std;

int lakeCount(vector<string>& field)
{
    int n = field.size(); // 场地的行数
    int ans = 0; //湖泊数量
    queue<pair<int, int>>  q; //广度优先搜索队列

    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};  // 横向移动的偏移量
    int dy[8] = {1, -1, 0 ,0, 1, -1, 1, -1};  // 纵向移动的偏移量

    for (int i = 0; i < n; i++) {
        int m = field[i].size(); // 当前行的列数
        for (int j = 0; j < m; j++) {
            if( field[i][j] == 'W')  //如果当前位置是水域
            {
                ans++;
                q.emplace(i,j);

                while(!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    // 遍历八个方向
                    for(int k = 0; i < 8; k++)
                    {
                        int nx = x + dx[k]; // 计算新的横坐标
                        int ny = y + dy[k]; // 计算新的纵坐标

                        // 判断边界，如果越界则忽略该方向
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (field[nx][ny] == 'W') { // 如果相邻位置是水域
                            field[nx][ny] = '.'; // 将相邻位置标记为已访问
                            q.emplace(nx, ny); // 将相邻位置加入广度优先搜索队列
                        }

                    }
                }
            }
        }
    }
    return ans; //返回湖泊数量
}