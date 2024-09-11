/**
* @file      longest_continuous_increasing_subsequence.cpp
* @author    Jinghui Zhang(zhangjh1220@gmail.com)
* @brief     LC #674. 最长连续递增序列
* @date      24-9-10
* @copyright Copyright (c) 2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1)    return nums.size();
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                dp[i] = dp[i - 1] + 1;
                res > dp[i] ? res : res = dp[i];
            }
        }

        return res;
    }
};