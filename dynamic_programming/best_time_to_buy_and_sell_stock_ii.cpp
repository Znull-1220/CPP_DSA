/**
* @file      best_time_to_buy_and_sell_stock_ii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #122.买卖股票的最佳时机II
* https://www.programmercarl.com/0122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAII%EF%BC%88%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%EF%BC%89.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-12
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0]表示第i天不持有股票的最大利润，dp[i][1]表示第i天持有股票的最大利润
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;   // 第一天不持有 0
        dp[0][1] = -prices[0];  // 第一天持有 那么利润就是负的股票价格
        for(int i = 1; i < prices.size(); i++) {
            // 不持有 要么前一天持有今天卖出 要么前一天不持有今天继续不持有
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 持有 要么前一天持有今天继续持有 要么前一天不持有今天买入
            // 可以买卖多次 那么要加上dp[i - 1][0] - prices[i] ；dp[i - 1][0]就是之前买卖过的利润
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[prices.size() - 1][0];    // 只返回不持有 因为不持有股票的利润肯定大于持有股票的利润
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}