/**
* @file      best_time_to_buy_and_sell_stock_iv.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #188.买卖股票的最佳时机IV
* 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
* 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
* 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
* @date      24-9-12
* @copyright Copyright (c) 2024
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // 这里最好设置dp[i][0] 代表第i天没有任何操作的最大利润 这样便于后面的递推
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        // 后面的思路和两次买入卖出是一样的
        for(int j = 1; j < 2 * k; j += 2) {
            dp[0][j] = -prices[0];
        }
        for(int i = 1; i < prices.size(); i++) {
            for(int j = 1; j < 2 * k; j += 2) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
            }
        }

        return dp[prices.size() - 1][2 * k];
    }
};

int main() {
    vector<int> prices = {2,4,1};
    int k = 2;
    Solution s;
    cout << s.maxProfit(k, prices) << endl;
    return 0;
}