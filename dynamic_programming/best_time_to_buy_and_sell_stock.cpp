/**
* @file      best_time_to_buy_and_sell_stock.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #121. 买卖股票的最佳时机
* @date      24-9-11
* @copyright Copyright (c) 2024
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution1 {
public:
    /*
     * 贪心
     */
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);  // 取最左最小价格
            result = max(result, prices[i] - low); // 直接取最大区间利润
        }
        return result;
    }
};

class Solution2 {
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
            // 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票
            // 所以不是dp[i - 1][0] - prices[i](这样是多次买入) 只能买入一次 是-prices[i]
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }

        return dp[prices.size() - 1][0];    // 只返回不持有 因为不持有股票的利润肯定大于持有股票的利润
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution1 s1;
    cout << s1.maxProfit(prices) << endl;
    Solution2 s2;
    cout << s2.maxProfit(prices) << endl;
    return 0;
}