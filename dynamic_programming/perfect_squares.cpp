/**
* @file      perfect_squares.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #279.完全平方数
* 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。
* 你需要让组成和的完全平方数的个数最少。
* 给你一个整数 n ，返回和为 n 的完全平方数的 最少数量
* https://www.programmercarl.com/0279.%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0.html#%E6%80%9D%E8%B7%AF
* @date      24-9-9
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;  // 其实就是考虑假设 9 的情况 那么只有3*3 一种
        // 这道题无所谓组合或排列，只是得到最少的数量
        // 先遍历物品 再遍历背包 反过来也是可以的
        for(int i = 1; i * i <= n; i++) {
            for(int j = i * i; j <= n; j++) {
                // 这个应该不用考虑之前凑不满的情况 因为1能组成任何数字
                dp[j]  = min(dp[j], dp[j - i * i] + 1);
            }
        }

        return dp[n];
    }
};

int main() {
    int n = 12;
    Solution solution;
    cout << solution.numSquares(n) << endl;
    return 0;
}