/**
* @file      integer_break.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #343. 整数拆分
* 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化
* 返回 你可以获得的最大乘积
* 输入: n = 10
* 输出: 36
* 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
* https://www.programmercarl.com/0343.%E6%95%B4%E6%95%B0%E6%8B%86%E5%88%86.html#%E6%80%9D%E8%B7%AF
* @date      24-8-26
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak1(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1; // 2拆分为1*1   严格来说dp[0]&dp[1]都是没有意义的 所以不用初始化
        for(int i = 3; i <= n; i++) {
            // 这里其实i / 2就够了，因为数组近似拆分的情况下最大值相等 这个数字肯定小于i/2
            // 注意这里是小于等于i/2 第一次没注意导致结果不对
            for(int j = 1; j <= i / 2; j++) {
                // j * (i - j)就是两个数字拆分 j * dp[i - j]就是继续拆分i - j 也就是2个及以上
                // 和dp[i]比较是因为 这个二层循环中dp[i]在不断更新 所以需要和之前的比较保证最大
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        return dp[n];
    }

    /**
     * 贪心 3是最优的拆分因子 不断用3分解直到剩余4，最后3*3*...*3 * 4是最大的
     */
    int integerBreak2(int n) {
        if(n == 2) {
            return 1;
        }
        if(n == 3) {
            return 2;
        }
        if(n == 4) {
            return 4;
        }

        int res = 1;

        while(n > 4) {
            res *= 3;
            n -= 3;
        }

        res *= n;
        return res;
    }
};

int main() {
    cout << Solution().integerBreak1(10) << endl;
    cout << Solution().integerBreak2(10) << endl;
}
