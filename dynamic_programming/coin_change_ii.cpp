/**
* @file      coin_change_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC 518.零钱兑换II
* 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
* 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0
* 假设每一种面额的硬币有无限个。
* https://www.programmercarl.com/0518.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2II.html#%E6%80%9D%E8%B7%AF
* @date      24-9-8
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0); // dp[i]表示凑成总金额i的硬币组合数
        // 分析：完全背包 + 组合背包问题 但注意是 *求组合* 而不是求排列
        // 完全背包 1D dp数组下 先遍历背包 再遍历物品都可以
        // 但求组合一定是先遍历物品 再遍历背包 否则每一个背包容量都经历了所有物品的计算 就变成了排列
        dp[0] = 1; // 可以理解为 dp[j - coin]; j - coin == 0 时候 刚好只有一种方法
        for(int coin : coins) {
            for(int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }

            for(const auto elem : dp) {
                cout << elem << " ";
            }
            cout << endl;
        }

        return dp[amount];
    }
};

int main() {
    Solution sl;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << sl.change(amount, coins) << endl;
    return 0;
}