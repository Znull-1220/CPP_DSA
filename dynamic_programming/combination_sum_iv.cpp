/**
* @file      combination_sum_iv.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC 377. 组合总和 Ⅳ
* 给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
* 请注意，顺序不同的序列被视作不同的组合。
* https://www.programmercarl.com/0377.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C%E2%85%A3.html#%E6%80%9D%E8%B7%AF
* @date      24-9-9
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<ull> dp(target + 1, 0); // dp[i]表示凑成总金额i的硬币组合数
        // 顺序不同的序列被视作不同的组合 所以这是一个排列问题 必须先遍历背包再遍历物品
        dp[0] = 1;
        for(int j = 1; j <= target; j++) {
            for (int num : nums) {
                if (num <= j) {
                    // LC oj 上会int overflow 用long long也还是溢出
                    // unsigned ll总算过了 或者int 判断一下不溢出也可以
                    dp[j] += dp[j - num];
                }
            }
        }

        return dp[target];
    }
};

int main() {
    Solution sl;
    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout << sl.combinationSum4(nums, target) << endl;
    return 0;
}
