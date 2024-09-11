/**
* @file      maximum_subarray_dp.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #53.最大子序和
* @date      24-9-11
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i]表示以nums[i]结尾的最大子序和
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        // 注意最大可不是dp[nums.size() - 1]，因为dp[i]表示以nums[i]结尾的最大子序和 不一定最后就是最大的
        // 所以需要记录并不断更新最大值
        int res = dp[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            if(res < dp[i])     res = dp[i];
        }

        return res;
    }
};