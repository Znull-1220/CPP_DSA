/**
* @file      best_time_to_buy_and_sell_stock_with_transaction_fee.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #714.买卖股票的最佳时机含手续费
* @date      24-9-12
* @copyright Copyright (c) 2024
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 这里我分析了三个状态，其实可以简化为两个状态，当天卖出的状态可以合并到不持有的状态也是可以的
class Solution1 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        // 0持有 1不持有 2当天卖出
        dp[0][0] = -prices[0];
        dp[0][2] = -fee;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1] - prices[i], dp[i - 1][2] - prices[i]});
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i] - fee;
        }

        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};


class Solution2 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] -= prices[0]; // 持股票
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};