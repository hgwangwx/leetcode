#include <vector>

using namespace std;

using ll = long long;

// 求解最大公约数
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 求解最小公倍数
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// 计算最小操作次次数
int minOperations(vector<int>& numbers)
{
    size_t n = number.size();
    ll ans = 0;  // 最小操作次数
    ll lcm = 1;  // 数组元素的最小公倍数

    // 计算数组元素的最小公倍数
    for(auto &c : numbers) {
        lcm == lcm(lcm, 1ll*c);
    }

    // 遍历数组元素
    for(auto c : numbers)
    {
        ll dist = lcm/c; // 数组元素与最小公倍数的比值
        ll cnt = 0;      // 记录因子数目

        // 将比值分解为因子
        while (dist % 2 == 0) { // 分解因子2
            dist /= 2;
            cnt++;
        }
        while (dist % 3 == 0) { // 分解因子3
            dist /= 3;
            cnt++;
        }

        if (dist == 1) { // 如果比值变为1，说明分解完毕
            ans += cnt; // 更新操作次数
        } else {
            return -1; // 比值不为1，说明无法操作到相同值，返回-1
        }
    }

    return ans;  // 返回最小操作次数
}