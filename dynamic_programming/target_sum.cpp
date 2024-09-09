/**
* @file      target_sum.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC 494. Target Sum 目标和
* https://www.programmercarl.com/0494.%E7%9B%AE%E6%A0%87%E5%92%8C.html#%E6%80%9D%E8%B7%AF
* @date      24-9-8
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

// 最直白的思路 分成两个集合，就可以直接转换为组合问题 用回溯爆搜
// 时间复杂度较高 用DP
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if(abs(target) > sum)
            return 0;
        // x - (sum - x) = target => x = (sum + target) / 2
        // (sum + target) / 2 不是整数，说明不存在这样的划分
        if((sum + target) % 2 == 1)
            return 0;
        int bag = (sum + target) / 2;
        /*
         * 这和之前的背包问题不同，之前的dp[i][j]内涵是前i个物品，背包容量为j时的最大价值
         * 而这道题是组合背包！！！ 这里的dp[i][j]内涵是前i个物品，凑成j的方法数
         * 只有刚好装满可以 装不满/装不下都不行
         */
        vector<int> dp(bag + 1, 0);
        dp[0] = 1;  // 容量为0时，只有一种方法，就是什么都不装
        // 1D背包 逆序遍历 先物品后背包容量
        for(int i = 0; i < nums.size(); i++) {
            // 只更新能放下当前数字的背包容量 就可以了
            // 因为2D dp 递推公式是 dp[i][j] = dp[i - 1][j] (放不下)
            // 或者 dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]] (放得下)
            for(int j = bag; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[bag];
    }
};