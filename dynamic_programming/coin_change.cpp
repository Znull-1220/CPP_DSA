/**
* @file      coin_change.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #322. 零钱兑换
* 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
* 如果没有任何一种硬币组合能组成总金额，返回 -1。
* 你可以认为每种硬币的数量是无限的。
* https://www.programmercarl.com/0322.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2.html#%E6%80%9D%E8%B7%AF
* @date      24-9-9
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX); // dp[i]表示凑成金额i所需的最少硬币数
        dp[0] = 0;  // 凑成金额0所需的最少硬币数为0
        for(int coin : coins) {
            for(int j = coin; j <= amount; j++) {
                // 因为是取最小 所以初始化为INT_MAX 防止比较错误
                if(dp[j - coin] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }

        if(dp[amount] == INT_MAX) return -1;    // 无法凑成
        return dp[amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution solution;
    cout << solution.coinChange(coins, amount) << endl;
    return 0;
}