/**
* @file      min_cost_climbing_stairs.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #746 Min Cost Climbing Stairs 爬楼梯的最小花费
* 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
* 一旦你支付此费用，即可选择向上爬一个或者两个台阶。你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
* 请你计算并返回达到楼梯顶部的最低花费。
* 示例
* 输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]    输出：6
* 解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。
* @date      24-8-24
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0); // dp[i]表示爬到第i阶楼梯的最小花费 最后+1就是到达顶部
        dp[0] = 0;
        dp[1] = 0;  // 从0/1开始，不需要花费 但从0开始，到达1阶需要花费cost[0]

        // cost.size() 就OK 别忘了idx 0 -> cost.size()
        for(int i = 2; i <= cost.size(); i++) {
            // 如果从i-1阶到i阶，花费cost[i-1] + dp[i - 1]，从i-2阶到i阶，花费cost[i-2]+dp[i-2]
            dp[i] = min(dp[i-1] + cost[i-1], dp[i - 2] + cost[i - 2]);
        }

        return dp[cost.size()];
    }
};


int main() {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout << Solution().minCostClimbingStairs(cost) << std::endl;
}