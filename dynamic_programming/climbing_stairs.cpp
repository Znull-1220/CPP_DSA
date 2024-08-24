/**
* @file      climbing_stairs.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #70 Climbing Stairs
* 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
* 每次你可以爬 1 或 2 个台阶, 你有多少种不同的方法可以爬到楼顶呢 注意：给定 n 是一个正整数
* 示例 ：
* 输入： 3;输出： 3
* 解释： 有三种方法可以爬到楼顶。
* 1 阶 + 1 阶 + 1 阶   1 阶 + 2 阶   2 阶 + 1 阶
* @date      24-8-24
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        // dp[i]表示爬到第i阶楼梯的方法数
        // dp[i] = dp[i-1] + dp[i-2]    (i >= 2)
        // 就是在爬到第i-1阶楼梯，再爬1阶；或者在爬到第i-2阶楼梯，再爬2阶
        if(n <= 1) {
            return n;   // n=0时，不需要爬，n=1时，只有一种方法 初始化严格来说不需要初始dp[0]
        }
        std::vector<int> dp(3, 0);
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++) {   // 优化空间复杂度
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }

        return dp[2];
    }
};

int main() {
    std::cout << Solution().climbStairs(4) << std::endl;
}