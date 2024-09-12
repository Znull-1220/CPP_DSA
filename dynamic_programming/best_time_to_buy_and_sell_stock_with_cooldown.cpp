/**
* @file      best_time_to_buy_and_sell_stock_with_cooldown.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     309.最佳买卖股票时机含冷冻期
* 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格
* 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
* 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
* 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)
* @date      24-9-12
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        // 可以划分四个状态 画一个状态机就很明显了
        // 1. 买入状态 2. 卖出状态 3. 今天卖出股票 4.冷冻期状态 (3 -> 4)
        // 买入只是一个status 并不是在当天必须买入
        dp[0][0] = -prices[0];
        for(int i = 1; i < prices.size(); i++) {
            // 买入状态 三种转移方式 前一天已经买入；前一天处于卖出；前一天处于冷冻期
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i],
                                dp[i - 1][3] - prices[i]));
            // 卖出状态 两种转移方式 前一天已经卖出；前一天处于冷冻期
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            // 今天卖出股票 只能从前一天买入的状态转移过来
            dp[i][2] = dp[i - 1][0] + prices[i];
            // 冷冻期状态 只能从前一天卖出的状态转移过来 没有任何操作
            dp[i][3] = dp[i - 1][2];
        }

        return max(dp[prices.size() - 1][1],
                    max(dp[prices.size() - 1][2],
                    dp[prices.size() - 1][3]));
    }
};