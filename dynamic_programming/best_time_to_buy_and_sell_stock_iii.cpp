/**
* @file      best_time_to_buy_and_sell_stock_iii.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #123.买卖股票的最佳时机III
* 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
* 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
* 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
* https://www.programmercarl.com/0123.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAIII.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-12
* @copyright Copyright (c) 2024
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())  return 0;
        // dp[i][0]代表在第i天第一次买入的最大利润 dp[i][1]代表在第i天第一次卖出的最大利润
        // dp[i][2]代表在第i天第二次买入的最大利润 dp[i][3]代表在第i天第二次卖出的最大利润
        // 本来还可以设置5个空间 这样dp[i][0]代表没有任何操作 其余往后顺延 但没有必要 可以做空间优化
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][2] = -prices[0];  // 第一/二次买入 第二次买入可以理解为一天做了一次买入卖出 又买入一次
        // 第一天的卖出 净利润都为0
        for(int i = 1; i < prices.size(); i++){
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }
        // 一定是两次买入卖出的金额最大 可以理解为在同一天买入卖出 并不一定是不同的四天
        return dp[prices.size() - 1][3];
    }
};

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}
