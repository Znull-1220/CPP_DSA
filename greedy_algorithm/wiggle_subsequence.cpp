/**
* @file      wiggle_subsequence.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #376. 摆动序列
* https://leetcode.cn/problems/wiggle-subsequence/description/
* https://www.programmercarl.com/0376.%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-9-3
* @copyright Copyright (c) 2024
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
public:
    /**
     * 思路1 贪心算法 贪心的对象是尽可能增加摆动，让波峰/波谷最多
     * 1. 上下坡中有平坡————平坡删左侧/右侧 统一删左侧 & 判断相等的情况
     * 2. 数组首尾两端————考虑n = 2的数组 res也是2 就假设res起始为1，默认最右边有一个峰
     * 3. 单调坡度有平坡————摆动时再更新preDiff
     */
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int res = 1;
        int preDiff = 0;
        int curDiff = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 只有preDiff可能 = 0 因为是统一删平坡的左侧
            if(curDiff > 0 && preDiff <= 0 || curDiff < 0 && preDiff >= 0) {
                res++;
                preDiff = curDiff;  // 保证摆动时再更新preDiff  避免单调坡度有平坡的错误情况
            }
        }

        return res;
    }

    /**
     * 思路2 DP
     */
    int wiggleMaxLength2(vector<int>& nums) {
        // 设 dp 状态dp[i][0]，表示考虑前 i 个数，第 i 个数作为山峰的摆动子序列的最长长度
        // 设 dp 状态dp[i][1]，表示考虑前 i 个数，第 i 个数作为山谷的摆动子序列的最长长度
        int dp[nums.size()][2];
        // memory set 以字节为单位为大片内存赋值
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        dp[0][1] = 1;   // 起点默认为1
        for(int i = 1; i < nums.size(); i++) {
            // 每个数字可以接到前面数字后作为山峰/山谷 也可以自身为子序列起点
            dp[i][0] = dp[i][1] = 1;
            // j < i 保证两个for同时初始化
            for(int j = 0; j < i; j++) {
                if(nums[j] > nums[i])
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }

            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i])
                    // 对i处理
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }

        return max(dp[nums.size() - 1][1], dp[nums.size() - 1][0]);
    }
};
