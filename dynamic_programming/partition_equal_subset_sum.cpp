/**
* @file      partition_equal_subset_sum.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #416. 分割等和子集
* 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
* 注意: 每个数组中的元素不会超过 100 数组的大小不会超过 200
* 示例 1:
* 输入: [1, 5, 11, 5]     输出: true    解释: 数组可以分割成 [1, 5, 5] 和 [11].
* 示例 2:
* 输入: [1, 2, 3, 5]      输出: false   解释: 数组不能分割成两个元素和相等的子集.
* https://www.programmercarl.com/0416.%E5%88%86%E5%89%B2%E7%AD%89%E5%92%8C%E5%AD%90%E9%9B%86.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
* @date      24-8-30
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        // OR: int sum = accumulate(nums.begin(), nums.end(), 0);
        for(int num : nums) {
            sum += num;
        }

        // 如果和为奇数，那么不可能分割成两个和相等的子集
        if(sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;   // 目标和
        // 思路就是将问题转化为背包问题，背包容量为sum / 2，物品重量为nums[i]，价值也为nums[i]
        // 因为只能放入一次 刚好是0/1背包问题
        // dp[j]的数值一定是小于等于j的 如果dp[j] == j 说明，集合中的子集总和正好可以凑成总和j
        vector<int> dp(target + 1, 0);

        for(int num : nums) {
            for(int j = target; j >= num; j--) {
                dp[j] = max(dp[j], dp[j - num] + num);
            }
        }

        if(dp[target] == target) {
            return true;
        }
        return false;
    }
};


int main() {
    Solution solution;
    vector<int> nums1 = {1, 5, 11, 5};
    cout << solution.canPartition(nums1) << endl;
    vector<int> num2 = {2, 3, 5, 1};
    cout << solution.canPartition(num2) << endl;
    return 0;
}